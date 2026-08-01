from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False  # 避免空矩陣錯誤
        
        fleft, fright = 0, len(matrix) - 1
        while fleft <= fright:
            middle = (fleft + fright) // 2
            if matrix[middle][0] > target:
                fright = middle - 1
            elif matrix[middle][0] < target:
                fleft = middle + 1
            else:
                return True
        
        row = fright  # 最終 `fright` 指向適當的行，確保 `row >= 0`
        if row < 0:
            return False

        # 搜尋該行
        sleft, sright = 0, len(matrix[0]) - 1
        while sleft <= sright:
            smiddle = (sleft + sright) // 2
            if matrix[row][smiddle] > target:
                sright = smiddle - 1
            elif matrix[row][smiddle] < target:
                sleft = smiddle + 1
            else:
                return True
        
        return False
