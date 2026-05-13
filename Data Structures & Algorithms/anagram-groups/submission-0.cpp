class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> out; 
        map<string, vector<string>> sorted_map;
        for(const auto& str: strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            auto find = sorted_map.find(temp);
            if(find == sorted_map.end()) {
                sorted_map[temp] = {str};
            } else {
                sorted_map[temp].push_back(str);
            }
        }
        for(const auto& pit: sorted_map) {
            out.push_back(pit.second);
        }
        return out;
    }
};
