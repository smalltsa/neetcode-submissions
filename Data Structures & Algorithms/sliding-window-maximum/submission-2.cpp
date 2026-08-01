class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;  // 儲存索引

        for (int rear = 0; rear < nums.size(); rear++) {
            // 1. 移除已經離開視窗的索引
            while (!dq.empty() && dq.front() <= rear - k) {
                dq.pop_front();
            }

            // 2. 移除尾端比目前元素小或相等的元素
            while (!dq.empty() && nums[dq.back()] <= nums[rear]) {
                dq.pop_back();
            }

            // 3. 加入目前元素的索引
            dq.push_back(rear);

            // 4. 視窗形成後，記錄最大值
            if (rear >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};