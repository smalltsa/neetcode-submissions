class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int target,
             int i, int sum, vector<int>& cur) {

        if (sum == target) {
            ans.push_back(cur);
            return;
        }

        if (sum > target || i == nums.size()) {
            return;
        }

        cur.push_back(nums[i]);
        dfs(nums, target, i, sum + nums[i], cur);
        cur.pop_back();

        dfs(nums, target, i + 1, sum, cur);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        dfs(nums, target, 0, 0, cur);
        return ans;
    }
};