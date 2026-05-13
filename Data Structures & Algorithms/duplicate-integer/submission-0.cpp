class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numd;
        for(auto& n : nums) {
		if(numd.contains(n)) 
			return true;
		numd.insert(n);
	}
	return false;
    }    
};
