class Solution:
    def maxArea(self, heights: List[int]) -> int:
        max_area = 0
        ln = 0
        i=0
        j = len(heights)-1
        while(i < j):
            ln = j - i
            area = ln * min(heights[i],heights[j])
            max_area = max(max_area,area)
            if heights[j] >= heights[i]:
                i+=1
            elif heights[j] < heights[i]:
                j-=1

        return  max_area 
            

