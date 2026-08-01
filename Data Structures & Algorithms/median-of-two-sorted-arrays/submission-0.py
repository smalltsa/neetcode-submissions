class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # 確保 nums1 是較短的陣列
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        m, n = len(nums1), len(nums2)
        left_size = (m + n + 1) // 2  # 左半部分的元素數量
        low, high = 0, m  # 在 nums1 上做二分搜尋

        while low <= high:
            x = (low + high) // 2  # nums1 左邊選擇 x 個元素
            y = left_size - x      # nums2 左邊選擇 y 個元素

            # 取邊界值，若超出範圍則設為負無窮或正無窮
            nums1_left_max = float('-inf') if x == 0 else nums1[x - 1]
            nums1_right_min = float('inf') if x == m else nums1[x]
            nums2_left_max = float('-inf') if y == 0 else nums2[y - 1]
            nums2_right_min = float('inf') if y == n else nums2[y]

            if nums1_left_max <= nums2_right_min and nums2_left_max <= nums1_right_min:
                # 找到正確分割，計算中位數
                if (m + n) % 2 == 1:
                    return max(nums1_left_max, nums2_left_max)  # 奇數長度
                else:
                    return (max(nums1_left_max, nums2_left_max) + min(nums1_right_min, nums2_right_min)) / 2  # 偶數長度
            elif nums1_left_max > nums2_right_min:
                high = x - 1  # 減少 nums1 左邊的元素
            else:
                low = x + 1  # 增加 nums1 左邊的元素

        return 0.0  # 理論上不會執行到這裡