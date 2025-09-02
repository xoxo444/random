#include <stdio.h>
#include <stdlib.h>

#define CANDIDATES 3

int votes[CANDIDATES] = {0};
char *names[CANDIDATES] = {"Alice", "Bob", "Charlie"};

void castVote() {
    int choice;
    printf("\n=== Cast Your Vote ===\n");
    for (int i = 0; i < CANDIDATES; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }
    printf("Enter your choice (1-%d): ", CANDIDATES);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= CANDIDATES) {
        votes[choice - 1]++;
        printf("Vote casted successfully for %s!\n", names[choice - 1]);
    } else {
        printf("Invalid choice. Try again.\n");
    }
}

void showResults() {
    printf("\n=== Voting Results ===\n");
    for (int i = 0; i < CANDIDATES; i++) {
        printf("%s: %d votes\n", names[i], votes[i]);
    }

    int maxVotes = votes[0], winnerIndex = 0;
    for (int i = 1; i < CANDIDATES; i++) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }
    printf("\n Winner: %s with %d votes!\n", names[winnerIndex], maxVotes);
}

int main() {
    int choice;
    while (1) {
        printf("~Voting System Menu~ \n");
        printf("1. Cast Vote\n");
        printf("2. Show Results\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                castVote();
                break;
            case 2:
                showResults();
                break;
            case 3:
                printf("Exiting. Thank you for voting!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
