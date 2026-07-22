class Solution {
public:
    vector<vector<int>> final;
    int size;
    vector<vector<int>> subsets(vector<int>& nums) {
        size = nums.size();
        sub(0, vector<int>(), nums);
        return final;
    }

    void sub(int i, vector<int> working, const vector<int> nums) {
        if(i == size) 
        {
            final.push_back(vector<int>(working.begin(), working.end()));
            return; 
        }

        working.push_back(nums.at(i));
        sub(i+1, working, nums);
        working.pop_back();
        sub(i+1, working, nums);
    }
};
