class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int a;
        set <int> dick;
        for (int i = 0; i < nums.size() ; i++){
            if (dick.count(nums[i])){
                return true;
            }else{
                dick.insert(nums[i]);
            }
        }
        return false;
    }
};
