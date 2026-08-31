class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& candidates, int i, int remain,
             vector<int>& cur) {

        if (remain == 0) {
            ans.push_back(cur);
            return;
        }

        if (i == candidates.size() || candidates[i] > remain) {
            return;
        }

        // 1. 選 candidates[i]
        cur.push_back(candidates[i]);
        dfs(candidates, i + 1, remain - candidates[i], cur);
        cur.pop_back();

        // 2. 不選 candidates[i]
        // 同樣的數字全部跳過，避免產生重複答案
        int next = i + 1;

        while (next < candidates.size() &&
               candidates[next] == candidates[i]) {
            next++;
        }

        dfs(candidates, next, remain, cur);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> cur;
        dfs(candidates, 0, target, cur);

        return ans;
    }
};