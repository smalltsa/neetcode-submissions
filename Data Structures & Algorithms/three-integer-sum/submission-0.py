class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        n = len(nums)
        
        for i in range(n - 2):
            # 避免重複計算相同的 nums[i]
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            target = -nums[i]
            front, rear = i + 1, n - 1

            while front < rear:
                total = nums[front] + nums[rear]
                if total > target:
                    rear -= 1
                elif total < target:
                    front += 1
                else:
                    ans.append([nums[i], nums[front], nums[rear]])

                    # 跳過重複的 front 值
                    while front < rear and nums[front] == nums[front + 1]:
                        front += 1
                    # 跳過重複的 rear 值
                    while front < rear and nums[rear] == nums[rear - 1]:
                        rear -= 1
                    
   
                    front += 1
                    rear -= 1
        
        return ans