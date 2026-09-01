class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int i){
        if (i == nums.size()){
            ans.push_back(nums);
            return;
        }
        for (int j = i;j < nums.size(); j++){
            swap(nums[i],nums[j]);
            dfs(nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return ans;
    }
};
