class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        vector<int> need(128, 0);

        // 記錄 t 中每個字元需要幾個
        for (char c : t) {
            need[c]++;
        }

        int missing = t.size();  // 還缺多少個字元
        int left = 0;

        int minStart = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            // need[c] > 0，代表這個字元目前仍然是需要的
            if (need[c] > 0) {
                missing--;
            }

            // 不論是否需要，都先扣掉
            // 多餘字元的數量會變成負數
            need[c]--;

            // 視窗已經包含 t 的所有字元
            while (missing == 0) {
                int windowLen = right - left + 1;

                if (windowLen < minLen) {
                    minLen = windowLen;
                    minStart = left;
                }

                char front = s[left];

                // 移除左端字元
                need[front]++;

                // need[front] > 0，代表移除後缺少這個字元
                if (need[front] > 0) {
                    missing++;
                }

                left++;
            }
        }

        return minLen == INT_MAX
            ? ""
            : s.substr(minStart, minLen);
    }
};