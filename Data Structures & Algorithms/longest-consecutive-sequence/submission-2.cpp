class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 使用雜湊集合，達到 O(1) 的尋找速度
        unordered_set<int> num_set(nums.begin(), nums.end());
        int max_longest = 0;

        for (int num : num_set) {
            // 【核心優化】只有當 num 是序列的「起點」時，才開始計算長度
            // 如果 num - 1 存在，說明 num 不是起點，直接跳過（後面會從起點算到它）
            if (num_set.find(num - 1) == num_set.end()) {
                int current_num = num;
                int current_streak = 1;

                // 不斷尋找下一個連續的數字
                while (num_set.find(current_num + 1) != num_set.end()) {
                    current_num += 1;
                    current_streak += 1;
                }

                // 更新全域最大長度
                max_longest = max(max_longest, current_streak);
            }
        }

        return max_longest;
    }
};