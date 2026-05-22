class Solution {
public:
    string minWindow(string s, string t) {
        int s_size {static_cast<int>(s.size())}, t_size{static_cast<int>(t.size())};
        unordered_map<char, int> t_map{}, window{};
        pair<int, int> shortest {0, s_size + 1};
        for(auto const& c: t) {
            t_map[c]++;
        } 
        int l{0};
        int matched {0};
        for(int r{0}; r < s_size; ++r) {
                window[s.at(r)]++;
                if(t_map.contains(s.at(r)) && window[s.at(r)] == t_map[s.at(r)])matched++;
            while(matched == t_map.size()) {
                if((r - l + 1) < shortest.second) {
                    shortest = {l, r - l + 1};
                }
                   window[s.at(l)]--;
                   if((t_map.contains(s.at(l))) && window[s.at(l)] < t_map[s.at(l)]) matched--;
                   l++;
            }
        }
        if(shortest.second > s_size) return "";
        return s.substr(shortest.first, shortest.second);
    }
};
