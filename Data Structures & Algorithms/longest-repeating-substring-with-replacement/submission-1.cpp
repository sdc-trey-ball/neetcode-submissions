class Solution {
public:
    int characterReplacement(string s, int k) {
        int size{static_cast<int>(s.size())};
        unordered_map<char, int> char_freq;
        int l{0};
        int max_streak {0};
        int max_f {0};
        for(int r {0}; r < size; ++r){
            char right = s.at(r);
            char left = s.at(l);
            char_freq[right]++;
            max_f =max(max_f, char_freq[right]);
            while((r- l+1) - max_f > k) {
                char_freq[left]--;
                l++;
            } 
            max_streak = max(max_streak, r - l + 1);
        }
        return max_streak;
    }
};
