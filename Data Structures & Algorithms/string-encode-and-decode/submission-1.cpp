class Solution {
public:

    string encode(vector<string>& strs) {
        string to_ret {};
        int length {};
        for(const auto& s : strs) {
           length = s.size(); 
           to_ret += to_string(length);
           to_ret += "#";
           to_ret += s;
        }
        return to_ret;
    }

    vector<string> decode(string s) {
        vector<string> to_ret {};
        for(int i = 0; i < s.size(); ) {
            string v {};
            string temp;
            while(s.at(i) != '#') {
                char cur = s.at(i++);
                v += cur; 
            }
            int val {stoi(v)};
            i++;
            int j = i;
            for(; j < i + val; j++) {
                temp += (s.at(j));
            }
            i = j;
            to_ret.push_back(temp);
        }
        return to_ret;
    }
};
