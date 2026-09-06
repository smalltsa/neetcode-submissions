class Solution {
public:
    unordered_map<char, string> keyb = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> ans;

    void dfs(string& digits, int i, string& cur) {
        if (i == digits.size()) {
            ans.push_back(cur);
            return;
        }

        for (char c : keyb[digits[i]]) {
            cur.push_back(c);

            dfs(digits, i + 1, cur);

            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string cur;
        dfs(digits, 0, cur);

        return ans;
    }
};