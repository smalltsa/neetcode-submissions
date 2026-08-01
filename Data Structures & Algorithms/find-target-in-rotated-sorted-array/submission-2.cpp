class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        // 1. 尋找最小值的索引（即旋轉點 pivot / front）
        while (left < right) {
            int middle = left + (right - left) / 2; // 防範溢位寫法
            if (nums[middle] > nums[right]) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }
        
        int pivot = left; // 此即為你思路中的 front
        
        // 2. 邏輯上的 Binary Search (將 0 到 n-1 視為標準遞增陣列)
        left = 0;
        right = n - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            
            // 透過模數映射找出實際的陣列 index
            int realMiddle = (middle + pivot) % n;
            
            if (nums[realMiddle] == target) {
                return realMiddle;
            }
            if (nums[realMiddle] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        
        return -1;
    }
};