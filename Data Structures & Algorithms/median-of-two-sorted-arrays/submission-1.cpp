#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1. 確保 nums1 是較短的陣列，這樣能將二分搜尋控制在 O(log(min(m, n)))
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left_size = (m + n + 1) / 2; // 左半部應該要有的總元素量

        int low = 0, high = m;

        while (low <= high) {
            int i = low + (high - low) / 2; // nums1 的切分點
            int j = left_size - i;          // nums2 的切分點（自動確定）

            // 處理邊界情況：若超過陣列邊界，用 INT_MIN / INT_MAX 代替
            int maxLeftA  = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRightA = (i == m) ? INT_MAX : nums1[i];

            int maxLeftB  = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRightB = (j == n) ? INT_MAX : nums2[j];

            // 檢查是否達到完美的切分狀態
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                // 找到完美切分點！開始計算中位數
                if ((m + n) % 2 == 1) {
                    // 總個數為奇數：中位數就是左半部的最大值
                    return max(maxLeftA, maxLeftB);
                } else {
                    // 總個數為偶數：中位數是（左半最大 + 右半最小）/ 2
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                }
            } 
            else if (maxLeftA > minRightB) {
                // nums1 切太靠右了，需要往左收縮
                high = i - 1;
            } 
            else {
                // nums1 切太靠左了（maxLeftB > minRightA），需要往右擴張
                low = i + 1;
            }
        }

        return 0.0;
    }
};