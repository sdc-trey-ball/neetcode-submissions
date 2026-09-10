class Solution {
public:
    map<int, bool> memo{};
    bool wordBreak(string s, vector<string>& wordDict) {
        int max_elem = max_element(wordDict.begin(), wordDict.end(), [](const string& a, const string& b){return a.length() < b.length();})->length();
        return dfs(s, wordDict, 0, 1, max_elem);
    }

    bool dfs(const string& s, const vector<string>& wordDict, int start, int len, const int& max_elem) {
        if(start == s.length()) return true;
        if(start + len > s.length()) return false;
        if(len > max_elem) return false;
        string sub{s.substr(start, len)};
        int i = start;
        if(memo.count(i)) return memo[i];
        if(find(wordDict.begin(), wordDict.end(), sub) != wordDict.end()) {
            memo[i] = dfs(s, wordDict, start + len, 1, max_elem) || dfs(s, wordDict, start, len + 1, max_elem);
            return memo[i];
        } else {
            memo[i] = dfs(s, wordDict, start, len + 1, max_elem);
            return memo[i];
        }
    }
};
