#ifndef UTILS_H
#define UTILS_H

#define TOTAL_STOCKS 10
#define MAX_STOCKS 10
#define MAX_NAME_LEN 50

extern char available_stocks[TOTAL_STOCKS][MAX_NAME_LEN];
extern float fixed_current_prices[TOTAL_STOCKS];

extern char stock_names[MAX_STOCKS][MAX_NAME_LEN];
extern float purchase_prices[MAX_STOCKS];
extern float current_prices[MAX_STOCKS];
extern float profit_losses[MAX_STOCKS];

extern int stock_count;

void calculate_profit_loss(int index);

#endif
