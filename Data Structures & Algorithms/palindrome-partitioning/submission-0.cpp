class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }

    void dfs(string& s, int start, vector<string>& cur) {

        // 整個字串都切完
        if (start == s.size()) {
            ans.push_back(cur);
            return;
        }

        // 枚舉這次要切到哪裡
        for (int end = start; end < s.size(); end++) {

            // 不是回文就不能選
            if (!isPalindrome(s, start, end)) {
                continue;
            }

            // 選 s[start...end]
            cur.push_back(
                s.substr(start, end - start + 1)
            );

            // 處理剩下部分
            dfs(s, end + 1, cur);

            // backtracking
            cur.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> cur;

        dfs(s, 0, cur);

        return ans;
    }
};