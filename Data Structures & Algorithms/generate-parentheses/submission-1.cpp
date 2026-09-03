class Solution {
public:
    vector<string> ans;

    void dfs(int n, int left, int right, string& cur) {
        // 左右括號都放完
        if (left == n && right == n) {
            ans.push_back(cur);
            return;
        }

        // 可以放左括號
        if (left < n) {
            cur.push_back('(');
            dfs(n, left + 1, right, cur);
            cur.pop_back();
        }

        // 可以放右括號
        if (right < left) {
            cur.push_back(')');
            dfs(n, left, right + 1, cur);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string cur;
        dfs(n, 0, 0, cur);
        return ans;
    }
};