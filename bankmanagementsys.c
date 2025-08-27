#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int acc_no;
    char name[50];
    float balance;
} Account;

Account acc;
FILE *fp;

void createAccount() {
    fp = fopen("bank.dat", "ab");
    if (!fp) {
        printf("File error!\n");
        return;
    }
    printf("Enter Account Number: ");
    scanf("%d", &acc.acc_no);
    printf("Enter Name: ");
    getchar(); // clear buffer
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = 0; // remove newline
    printf("Enter Initial Balance: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);
    printf("Account created successfully!\n");
}

void displayAccounts() {
    fp = fopen("bank.dat", "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }
    printf("\n--- All Accounts ---\n");
    while (fread(&acc, sizeof(Account), 1, fp)) {
        printf("Acc No: %d | Name: %s | Balance: %.2f\n", acc.acc_no, acc.name, acc.balance);
    }
    fclose(fp);
}

void searchAccount() {
    int no, found = 0;
    fp = fopen("bank.dat", "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }
    printf("Enter Account Number to Search: ");
    scanf("%d", &no);
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.acc_no == no) {
            printf("Acc No: %d | Name: %s | Balance: %.2f\n", acc.acc_no, acc.name, acc.balance);
            found = 1;
            break;
        }
    }
    if (!found) printf("Account not found!\n");
    fclose(fp);
}

void depositMoney() {
    int no, found = 0;
    float amt;
    FILE *temp;
    fp = fopen("bank.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (!fp || !temp) {
        printf("File error!\n");
        return;
    }
    printf("Enter Account Number: ");
    scanf("%d", &no);
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.acc_no == no) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amt);
            acc.balance += amt;
            printf("Updated Balance: %.2f\n", acc.balance);
            found = 1;
        }
        fwrite(&acc, sizeof(Account), 1, temp);
    }
    fclose(fp);
    fclose(temp);
    remove("bank.dat");
    rename("temp.dat", "bank.dat");
    if (!found) printf("Account not found!\n");
}

void withdrawMoney() {
    int no, found = 0;
    float amt;
    FILE *temp;
    fp = fopen("bank.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (!fp || !temp) {
        printf("File error!\n");
        return;
    }
    printf("Enter Account Number: ");
    scanf("%d", &no);
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.acc_no == no) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amt);
            if (amt > acc.balance) {
                printf("Insufficient balance!\n");
            } else {
                acc.balance -= amt;
                printf("Updated Balance: %.2f\n", acc.balance);
            }
            found = 1;
        }
        fwrite(&acc, sizeof(Account), 1, temp);
    }
    fclose(fp);
    fclose(temp);
    remove("bank.dat");
    rename("temp.dat", "bank.dat");
    if (!found) printf("Account not found!\n");
}


int main() {
    int choice;
    while (1) {
        printf("\n--- Bank Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

      
        switch (choice) {
            case 1: createAccount(); break;
            case 2: displayAccounts(); break;
            case 3: searchAccount(); break;
            case 4: depositMoney(); break;
            case 5: withdrawMoney(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
