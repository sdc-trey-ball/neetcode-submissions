class Solution {
public:
    bool isPalindrome(string s) {
        int l {0}, r {static_cast<int>(s.size() - 1)};
        char cur_l, cur_r;
        while(l < r) {
            if(!isalnum(s.at(l))) {
                l++;
                continue;
            } else if(!isalnum(s.at(r))) {
                r--;
                continue;
            } 
            if(tolower(s.at(l++)) != tolower(s.at(r--))) return false;
        }
        return true;
    }
};
