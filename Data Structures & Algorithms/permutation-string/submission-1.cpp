class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       //fixed size window
       int s1_size{static_cast<int>(s1.size())}, s2_size{static_cast<int>(s2.size())};
        unordered_map<char, int> s1_map{}, window{};
       if(s1_size > s2_size) return false;
       int l {0}, r{s1_size - 1};
       cout << "init " << l << " " << r <<endl;
       for(int i{0}; i < s1.size(); ++i) {
            s1_map[s1.at(i)]++;
       }
       for(int r {0}; r < s2_size; ++r) {
            window[s2.at(r)]++;
            if(r - l + 1 > s1_size) {
                window[s2.at(l)]--;
                if(window[s2.at(l)] == 0) {
                    window.erase(s2.at(l));
                }
                l++;
            }
            if(window == s1_map){
                return true;
            }
       }
       return false;
       //frew map of s1

    }
};
