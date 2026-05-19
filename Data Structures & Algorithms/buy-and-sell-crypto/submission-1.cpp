class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int min_price {prices.at(0)};
       int best_profit {0};
       int size {static_cast<int>(prices.size())};
       for(int i{1}; i < size; ++i) {
            best_profit = max(best_profit, prices.at(i) - min_price);
            min_price = min(prices.at(i), min_price);
       }
       return best_profit;
    }
};
