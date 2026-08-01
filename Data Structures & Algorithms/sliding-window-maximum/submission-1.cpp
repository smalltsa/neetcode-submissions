class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        for (int front = 0; front + k <= nums.size(); front++) {
            int windowMax = nums[front];

            for (int i = front; i < front + k; i++) {
                windowMax = max(windowMax, nums[i]);
            }

            ans.push_back(windowMax);
        }

        return ans;
    }
};