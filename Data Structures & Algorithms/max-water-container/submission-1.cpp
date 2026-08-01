class Solution {
public:
    int maxArea(vector<int>& heights) {
        // 1. 將變數 max 改名為 max_val，避免與 std::max 衝突
        int front = 0, rear = heights.size() - 1, max_val = 0; 
        
        while(rear > front){
            int k   = min(heights[front], heights[rear]);
            int l   = rear - front;
            int now = k * l;
            
            // 2. 使用 std::max，且寫入剛剛改名後的變數
            max_val = std::max(max_val, now); 
            
            if (heights[front] >= heights[rear]){
                rear--;
            } else {
                front++;
            }
        }
        return max_val;
    }
};