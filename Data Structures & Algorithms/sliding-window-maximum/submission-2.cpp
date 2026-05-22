class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q{};
        vector<int> out{};
        int l {0}, r{0};
        while (r < nums.size()) {
            while(!q.empty() && nums[q.front()] < nums[r]) {
                q.pop_front();
            }
            q.push_front(r);
            if(q.back() < l) {
                q.pop_back();
            }
            if(r + 1 >= k){
                out.push_back(nums[q.back()]);
                l++;
            }
            r++;
        }
        return out;
    }
};
