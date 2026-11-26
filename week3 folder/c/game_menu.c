// PROGRAM 7: Game menu (intentional fall-through from Start to shared loading)
#include <stdio.h>
int main(void) {
    int choice;
    printf("===== MAIN MENU =====\n1. Start Game\n2. Load Game\n3. Settings\n4. Credits\n5. Exit\nEnter your choice: ");
    if (scanf("%d", &choice) != 1) return 1;
    switch (choice) {
        case 1: printf("Starting new game...\n"); /* intentional fall-through */
        case 2: printf("Loading game assets...\nGame ready!\n"); break;
        case 3: printf("Opening settings...\n"); break;
        case 4: printf("Game developed by CS Students\n"); break;
        case 5: printf("Goodbye!\n"); break;
        default: printf("Invalid choice. Please try again.\n"); break;
    }
    return 0;
}
