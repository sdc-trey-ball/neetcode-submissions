class Solution {
public:
    vector<string> formed_parens;
    vector<string> generateParenthesis(int n) {
        eval(n, 0, 0, "");
        return formed_parens;
    }

    void eval(const int n, int opened, int closed, string cur) {
        if(opened == closed) {
            if(closed == n) {
                formed_parens.push_back(cur);
                return;
            }
            cur.push_back('(');
            eval(n, opened + 1, closed, cur);
            return;
        }
        if(opened == n) {
            cur.push_back(')');
            eval(n, opened, closed + 1, cur);
            return;
        }

        cur.push_back('(');
        eval(n, opened + 1, closed, cur);
        cur.pop_back();
        cur.push_back(')');
        eval(n, opened, closed + 1, cur);
    }
};
