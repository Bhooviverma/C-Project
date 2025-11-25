#include <stdio.h>
#include <string.h>
#include "utils.h"

#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

void buy_stock_logic() {
    if (stock_count >= MAX_STOCKS) {
        printf(RED "Portfolio is full!\n" RESET);
        return;
    }

    printf("Available Stocks:\n");
    for (int i = 0; i < TOTAL_STOCKS; i++) {
        printf("%2d. %-25s | Rs.%.2f\n",
               i + 1, available_stocks[i], fixed_current_prices[i]);
    }

    int choice;
    printf("Enter stock number (1-%d): ", TOTAL_STOCKS);
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > TOTAL_STOCKS) {
        printf(RED "Invalid selection.\n" RESET);
        while (getchar() != '\n');
        return;
    }

    int index = choice - 1;

    strcpy(stock_names[stock_count], available_stocks[index]);
    current_prices[stock_count] = fixed_current_prices[index];

    printf("Enter purchase price for %s: Rs.", stock_names[stock_count]);
    if (scanf("%f", &purchase_prices[stock_count]) != 1 ||
        purchase_prices[stock_count] <= 0) {
        printf(RED "Invalid price.\n" RESET);
        while (getchar() != '\n');
        return;
    }

    calculate_profit_loss(stock_count);
    stock_count++;

    printf(GREEN "Stock purchased successfully!\n" RESET);
}
