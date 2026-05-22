class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       int l {0}, size {static_cast<int>(nums.size())};
       int max {numeric_limits<int>::min()};
       priority_queue<int> maxed{nums.begin(), nums.begin() + k - 1};
       vector<int> out{};
       map<int, int> unpopped {};
       while(l + k <= size) {
            maxed.push(nums.at(l + k - 1));
            out.push_back(maxed.top());
            if(nums.at(l) != maxed.top()) unpopped[nums.at(l)]++;
            else {
               maxed.pop(); 
            while(!maxed.empty() && unpopped.contains(maxed.top())) {
                cout << l << " " << maxed.top() << " " << unpopped.size() << endl;
                unpopped[maxed.top()]--;
                if(unpopped[maxed.top()] == 0)  unpopped.erase(maxed.top());
                maxed.pop();
            }
       }
            l++;
       }
       return out;
    }
};
