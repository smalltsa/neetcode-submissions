class Solution {
public:
    int search(vector<int>& nums, int target) {
        int front = 0 , rear = nums.size()-1;
        while(rear >= front){
            int middle = (rear + front) / 2;
            if (nums[middle] == target){
                return middle;
            }else if(nums[middle] < target){
                    front = middle + 1;
            }else{
                    rear = middle - 1;
            }
        }
        return -1;
    }
};
