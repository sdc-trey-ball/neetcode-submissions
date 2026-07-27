class Solution {
public:
    vector<string> formed_parens;
    vector<string> generateParenthesis(int n) {
        eval(n, 0, 0, "");
        return formed_parens;
    }

    void eval(const int n, int opened, int closed, string cur) {
        if(opened == closed && opened == n) {
            formed_parens.push_back(cur);
            return;
        }
        if(opened < n) {
            cur.push_back('(');
            eval(n, opened + 1, closed, cur);
            cur.pop_back();
        }
        if(closed < opened) {
            cur.push_back(')');
            eval(n, opened, closed + 1, cur);
        }
    }
};
