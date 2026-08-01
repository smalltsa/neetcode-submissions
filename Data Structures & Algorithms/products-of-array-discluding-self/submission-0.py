class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        nsum = 1
        count = 0
        for i in nums:
            nsum = i * nsum
            if i == 0:
                count+=1
        ans = []
        tmp = 1
        for i in nums:
            if count >=2:
                ans.append(0)    
            elif i!=0:
                ans.append(nsum//i)
            elif i==0:
                for j in nums:
                    if j==0:
                        continue
                    else:
                        tmp = tmp*j
                ans.append(tmp) 
        return ans
            