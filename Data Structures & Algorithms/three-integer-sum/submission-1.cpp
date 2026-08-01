class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i = 0; i < nums.size(); i++){
            // 修正點 1: 去重。如果這個起點數字跟上一個一樣，直接跳過以免產生重複答案
            if (i > 0 && nums[i] == nums[i-1]) continue; 
            
            int now = nums[i];
            int front = i + 1;
            int rear = nums.size() - 1;
            
            while(rear > front){
                int sum = now + nums[front] + nums[rear];
                
                if(sum == 0){
                    ans.push_back({nums[i], nums[front], nums[rear]}); // 簡化語法
                    
                    // 修正點 2: 找到答案後必須移動指針，否則會死迴圈！
                    front++;
                    rear--;
                    
                    // 修正點 3: 雙指針內部的去重，跳過相同的數字
                    while(rear > front && nums[front] == nums[front-1]) front++;
                    while(rear > front && nums[rear] == nums[rear+1]) rear--;
                    
                } else if (sum > 0){
                    rear--;
                } else {
                    front++;
                }
            }
        }
        return ans;
    }
};