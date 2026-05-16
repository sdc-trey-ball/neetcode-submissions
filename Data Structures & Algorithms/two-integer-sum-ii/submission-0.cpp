class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l {0}, r{static_cast<int>(numbers.size() - 1)};
        int sum {};
        while(l < r) {
            sum = numbers.at(l) + numbers.at(r);
            if(target == sum) return {l + 1, r + 1};
            else if(sum > target) r--;
            else l++;
        }
        return {};
    }
};
