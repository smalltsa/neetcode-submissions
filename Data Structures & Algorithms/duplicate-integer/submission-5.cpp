class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen; 
        int n = nums.size(); 
        int i;
        
        for (i = 0; i < n; i++) {
            if (seen.count(nums[i])) {
                return true;
            } else {
                seen[nums[i]] = 1; 
            }
        }
        return false;    
    }
};