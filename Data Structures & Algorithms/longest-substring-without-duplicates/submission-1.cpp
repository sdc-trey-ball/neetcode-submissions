class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        int l{0}, r{0}, max_s{1};
        int size{static_cast<int>(s.size())};
        while(r < size) {
            if(l == r) {
                r++;
                continue;
            }
            if(s.substr(l, r -l).find(s.at(r)) != string::npos) {
                cout << l << " " << r << " " << (s.substr(l, r)) << endl;
                l++;
            } else {
                max_s = max(max_s, r - l + 1);
                cout << l << " " << r << " " << max_s << endl;
                r++;
            }
        }
        return max_s;
    }
};
