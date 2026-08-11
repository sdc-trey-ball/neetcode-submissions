class Solution {
public:
    int numDecodings(string s) {
        if(s.at(0) == '0') return 0;
        int b2{0}, b1{1};
        bool po{false};
        for(int i{0}; i < s.length(); ++i) {
            if(!po && s.at(i) == '0') return 0;
            int temp = b2;
            b2 = b1;
            bool can_split = 
                po &&
                ((s.at(i) - '0') < 7 || s.at(i - 1) == '1') &&
                (s.at(i)) != '0';
            if(i < s.length() - 1) {
                can_split = can_split && (s.at(i+1) != '0');
                cout << "can_split = " << can_split << " ";
            }
            b1 = can_split ? b1 + temp : b1;
            po = (s.at(i) == '1' || s.at(i) == '2');
            cout << "i: " << i << " b1: " << b1 << " b2: " << b2 << " po: " << (po ? "true" : "false") << '\n';
        }
        return b1;
    }
};
