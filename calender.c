#include <stdio.h>

// Function to check leap year
int isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int getDaysInMonth(int month, int year) {
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

// Zeller's Congruence to get day of week
// 0 = Saturday, 1 = Sunday, ..., 6 = Friday
int getStartDay(int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int q = 1;  // Day of month
    int k = year % 100;
    int j = year / 100;
    int h = (q + (13*(month + 1))/5 + k + (k/4) + (j/4) + 5*j) % 7;
    return h;
}

int main() {
    int month, year;

    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    if (month < 1 || month > 12 || year < 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int days = getDaysInMonth(month, year);
    int startDay = getStartDay(month, year);

    // Adjust startDay to make Sunday = 0, Monday = 1, ...
    // Since Zeller returns 0=Saturday, convert it:
    startDay = (startDay + 6) % 7;

    // Month names
    const char* months[] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};

    printf("\n  Calendar - %s %d\n", months[month-1], year);
    printf("Su Mo Tu We Th Fr Sa\n");

    // Print spaces before the first day
    for (int i = 0; i < startDay; i++) {
        printf("   ");
    }

    // Print all days of the month
    for (int day = 1; day <= days; day++) {
        printf("%2d ", day);

        if ((day + startDay) % 7 == 0)
            printf("\n");
    }
    printf("\n");

    return 0;
}
