from typing import List
import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        lower, upper = 1, max(piles)
        res = upper

        while lower <= upper:  # 正確的條件
            middle = (upper + lower) // 2
            sumh = sum(math.ceil(i / middle) for i in piles)  # 簡化計算

            if sumh > h:  # 吃太慢，增加速度
                lower = middle + 1
            else:  # sumh <= h 時，縮小可能範圍
                upper = middle - 1
                res = min(res, middle)  # 更新最小可能速度

        return res
