class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> counts;

        for (int num : nums) {
            counts[num]++;
        }
        vector<vector<int>> buckets( n + 1);
        for (auto& p : counts) {
            int num = p.first;
            int freq = p.second;
            buckets[freq].push_back(num);
        }
        vector<int> ans;
        for (int i = n; i >=0 ; i--){
            for (int num:buckets[i]){
                ans.push_back(num);

                if (ans.size()==k){
                    return ans;
                }
            }
        }
    } 
};
