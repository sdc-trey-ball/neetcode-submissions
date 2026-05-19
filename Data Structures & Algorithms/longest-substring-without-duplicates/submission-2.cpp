class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        int l{0}, r{0}, max_s{1};
        int size{static_cast<int>(s.size())};
        unordered_set<char> window{};
        window.insert(s.at(0));
        while(r < size) {
            if(l == r) {
                r++;
                continue;
            }
            if(window.count(s.at(r)) != 0) {
                cout << l << " " << r << " " << (window.size()) << endl;
                window.erase(s.at(l));
                l++;
                window.insert(s.at(l));
            } else {
                max_s = max(max_s, r - l + 1);
                cout << l << " " << r << " " << max_s << endl;
                window.insert(s.at(r));
                r++;
            }
        }
        return max_s;
    }
};
