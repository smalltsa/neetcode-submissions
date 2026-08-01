class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> table;
        for (int i = 0;i < nums.size();i++){
            table[nums[i]]++;
        }
        vector<pair<int,int>> freq_vec(table.begin(),table.end());
        sort(freq_vec.begin(),freq_vec.end(),[](const pair<int,int>& a,const pair<int,int> & b){
            return a.second > b.second;
        });
        vector<int> ans;
        for (int i = 0 ;i < k ; i++){
            ans.push_back(freq_vec[i].first);
        }
        return ans;
    } 
};
