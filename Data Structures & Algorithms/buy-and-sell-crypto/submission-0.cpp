class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int max_profit {0};
       int buy{0}, sell {0};
       int size {static_cast<int>(prices.size())};
       while(sell < size) {
            int buy_value = prices.at(buy);
            int sell_value = prices.at(sell);
            if(buy == sell) {
                sell++;
                continue;
            } else {
                max_profit = max(max_profit, sell_value - buy_value);
                if(buy_value > sell_value) buy = sell;
                else sell++;
            }
       }
       return max_profit;
    }
};
