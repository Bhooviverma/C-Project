#include <stdio.h>

#include "buy_logic.h"
#include "sell_logic.h"
#include "portfolio_display.h"

void display_menu() {
    printf("\n==========================================\n");
    printf("         STOCK PORTFOLIO MANAGER\n");
    printf("==========================================\n");
    printf("1. Buy Stock\n");
    printf("2. View Portfolio\n");
    printf("3. Sell Stock\n");
    printf("4. Exit\n");
    printf("------------------------------------------\n");
}

int main() {
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: buy_stock_logic(); break;
            case 2: display_portfolio_logic(); break;
            case 3: sell_stock_logic(); break;
            case 4: printf("Goodbye!\n"); break;

            default: printf("Enter 1–4 only.\n");
        }

    } while (choice != 4);

    return 0;
}