class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(vector<int>& nums, int target, int start) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (nums[i] > target)
                continue;

            cur.push_back(nums[i]);
            dfs(nums, target - nums[i], i);  // i 不加 1，可重複使用
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums, target, 0);
        return ans;
    }
};