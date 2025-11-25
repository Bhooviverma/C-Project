#include <stdio.h>
#include <string.h>
#include "utils.h"

char available_stocks[TOTAL_STOCKS][MAX_NAME_LEN] = {
    "Reliance Industries", "Tata Motors", "Infosys", "HDFC Bank", "ITC Limited",
    "Bharti Airtel", "State Bank of India", "Hindustan Unilever", "Wipro", "Adani Enterprises"
};

float fixed_current_prices[TOTAL_STOCKS] = {
    2850.50, 890.75, 1630.25, 1655.00, 452.10,
    975.40, 742.20, 2600.00, 490.60, 3200.80
};

char stock_names[MAX_STOCKS][MAX_NAME_LEN];
float purchase_prices[MAX_STOCKS];
float current_prices[MAX_STOCKS];
float profit_losses[MAX_STOCKS];

int stock_count = 0;

void calculate_profit_loss(int index) {
    profit_losses[index] = current_prices[index] - purchase_prices[index];
}