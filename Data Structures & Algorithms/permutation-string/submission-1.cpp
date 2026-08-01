class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        unordered_map<char, int> dict;
        unordered_map<char, int> window;

        int windowSize = s1.size();

        // 統計 s1 每個字元的數量
        for (char c : s1) {
            dict[c]++;
        }

        // 建立第一個固定長度的 window
        for (int i = 0; i < windowSize; i++) {
            window[s2[i]]++;
        }

        // 比較第一個 window
        if (dict == window) {
            return true;
        }

        // rear 指向即將加入 window 的字元
        for (int rear = windowSize; rear < s2.size(); rear++) {
            int front = rear - windowSize;

            // 移除最左側字元
            window[s2[front]]--;

            // 次數歸零時刪除，避免 unordered_map 比較失敗
            if (window[s2[front]] == 0) {
                window.erase(s2[front]);
            }

            // 加入右側新字元
            window[s2[rear]]++;

            if (dict == window) {
                return true;
            }
        }

        return false;
    }
};