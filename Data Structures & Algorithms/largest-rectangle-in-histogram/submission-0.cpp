class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_height {0};
        stack<pair<int,int>> running_max;
        int size {static_cast<int>(heights.size())};
        running_max.push({0, heights.at(0)});
        for(int i {1}; i < size; ++i) {
            int val = heights.at(i);
            auto top_pair = running_max.top();
            if(top_pair.second <= val) {
                running_max.push({i, val});
            } else {
                while(!running_max.empty() &&running_max.top().second > val) {
                    top_pair = running_max.top();
                    max_height = max(max_height,  (i - top_pair.first)*top_pair.second);
                    running_max.pop();
                }
                running_max.push({top_pair.first, val});
            } 
        }
        while(!running_max.empty()) {
            auto top_pair = running_max.top();
            max_height = max(max_height,  (size - top_pair.first)*top_pair.second);
            running_max.pop();
        }
        return max_height;
    }
};
