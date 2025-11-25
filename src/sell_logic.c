#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "portfolio_display.h"

#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

void sell_stock_logic() {
    if (stock_count == 0) {
        printf(RED "Nothing to sell.\n" RESET);
        return;
    }

    display_portfolio_logic();

    int no;
    printf("\nEnter stock number to sell (1-%d): ", stock_count);
    if (scanf("%d", &no) != 1 || no < 1 || no > stock_count) {
        printf(RED "Invalid.\n" RESET);
        while (getchar() != '\n');
        return;
    }

    int index = no - 1;

    printf("Sell %s? (y/n): ", stock_names[index]);
    while (getchar() != '\n');
    char c = getchar();

    if (c != 'y' && c != 'Y') {
        printf(RED "Cancelled.\n" RESET);
        return;
    }

    const char* color = (profit_losses[index] >= 0) ? GREEN : RED;

    printf("\nSOLD: %s | P/L: %s%.2f%s\n",
           stock_names[index], color, profit_losses[index], RESET);

    for (int i = index; i < stock_count - 1; i++) {
        strcpy(stock_names[i], stock_names[i + 1]);
        purchase_prices[i] = purchase_prices[i + 1];
        current_prices[i] = current_prices[i + 1];
        profit_losses[i] = profit_losses[i + 1];
    }

    stock_count--;
}
