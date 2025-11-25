#include <stdio.h>
#include "utils.h"

#define RED "\033[1;31m"
#define RESET "\033[0m"

void update_current_prices() {
    printf("\nUpdate current market prices:\n");

    for (int i = 0; i < stock_count; i++) {
        printf("Enter price for %s (Prev: Rs.%.2f): Rs.",
               stock_names[i], current_prices[i]);

        float np;
        if (scanf("%f", &np) != 1 || np <= 0) {
            printf(RED "Invalid price. Using previous value.\n" RESET);
            while (getchar() != '\n');
            continue;
        }

        current_prices[i] = np;
        calculate_profit_loss(i);
    }
}
