from collections import Counter
from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_map = Counter(nums)  # 計算每個數字出現的頻率
        bucket = [[] for _ in range(len(nums) + 1)]

        # 把數字根據出現頻率放入 bucket
        for num, freq in freq_map.items():
            bucket[freq].append(num)

        ans = []
        # 從最高頻率開始往下遍歷
        for i in range(len(bucket) - 1, 0, -1):
            for num in bucket[i]:
                ans.append(num)
                if len(ans) == k:
                    return ans