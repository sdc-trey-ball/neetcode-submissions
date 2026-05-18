class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       // stack of val to indices
       // output vector init to all 0
       // compare top keep popping til find bigger and then puyt on stack
       int size = static_cast<int>(temperatures.size());
       vector<int> to_ret(size, 0);
       stack<pair<int, int>> val_pair;
       val_pair.push({temperatures.at(0), 0});
       int temp{};
       pair<int, int> found{};
       for(int i{0}; i < size; ++i) {
            temp = temperatures.at(i);
            while(!val_pair.empty() &&val_pair.top().first < temp) {
                found = val_pair.top();
                val_pair.pop();
                to_ret.at(found.second) = i - found.second;
            }
            val_pair.push(pair<int,int>(temp, i));
       }
       return to_ret;
    }
};
