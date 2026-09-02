class Solution {
public:
    vector <vector<int>> ans;
    vector <int> cur;
    void dfs(vector<int>& nums,int i){
        if(i == nums.size()){
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        dfs(nums,i+1);
        cur.pop_back();

        int next = i+1;

        while(next < nums.size() && nums[next] == nums[i]){
            next++;
        }
        dfs(nums,next);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return ans;
    }
};
