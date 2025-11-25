#include <stdio.h>
#include "utils.h"
#include "update_prices.h"

#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE  "\033[1;34m"
#define RESET "\033[0m"

void display_portfolio_logic() {
    if (stock_count == 0) {
        printf(RED "Portfolio empty.\n" RESET);
        return;
    }

    update_current_prices();

    float total = 0, totalPL = 0;

    printf("======================================================================================\n");
    printf(BLUE "                            CURRENT PORTFOLIO\n" RESET);
    printf("======================================================================================\n");

    for (int i = 0; i < stock_count; i++) {
        const char* color = (profit_losses[i] >= 0) ? GREEN : RED;

        printf("%2d. %-25s | Buy: %.2f | Now: %.2f | %s%.2f%s\n",
               i + 1, stock_names[i], purchase_prices[i], current_prices[i],
               color, profit_losses[i], RESET);

        total += current_prices[i];
        totalPL += profit_losses[i];
    }

    const char* tcolor = (totalPL >= 0) ? GREEN : RED;

    printf("======================================================================================\n");
    printf("Total Value: Rs.%.2f | Net P/L: %s%.2f%s\n",
           total, tcolor, totalPL, RESET);
    printf("======================================================================================\n");
}
