class Solution {
public:
    bool isValid(string s) {
        //stack of brackets
        //make set of chars to check in to mimic multiple if checks
        // if not at top return false and if at end and stack not empty return false
        vector<char> openings {'{', '[', '('}, closings{'}', ']', ')'};
        int size {static_cast<int>(s.length())};
        stack<char> st{};
        vector<char>::iterator it;
        char c{};
        for(int i{0}; i < size; ++i){
            c = s.at(i);
            it = find(openings.begin(), openings.end(), c) ;
            if(it != openings.end()) {
                st.push(c);
                continue;
            } 
            it = find(closings.begin(), closings.end(), c) ;
            if(it != closings.end()) {
                if(st.empty() || openings.at(distance(closings.begin(), it)) != st.top()) return false;
                st.pop();
            } 
        }
        return st.empty();
    }
};
