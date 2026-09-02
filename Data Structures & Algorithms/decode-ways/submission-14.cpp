class Solution {
public:
    int numDecodings(string s) {
        int prev{0}, decodings{1}, prev_decodings{1};
        bool prev_joined{false};

        for(int i {0}; i < s.length(); ++i) {
            int cur = s.at(i) - '0'; 
            bool joined{false};
            if(cur == 0) {
               if(prev == 0 || prev > 2) return 0; 
            } else if(prev > 0 && prev <= 2) {
                if((i + 1 >= s.length() || s.at(i + 1) - '0' != 0) && (prev == 1 || cur < 7)) {
                cout << i << " " << decodings << " split\n";
                    joined = true;
                    int temp {decodings}; 
                    if(prev_joined) {
                        decodings += prev_decodings;    
                    } else {
                        decodings *= 2;
                    }
                    prev_decodings = temp;
                }
            } 
            prev = cur;
            prev_joined = joined;
        }
        return decodings;
    }
};
