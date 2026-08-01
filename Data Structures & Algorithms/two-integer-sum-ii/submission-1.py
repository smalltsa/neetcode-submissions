class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        front,rear = 0,len(numbers)-1
        while(rear>front):
            if numbers[front] + numbers[rear] > target:
                rear-=1
            elif numbers[front] + numbers[rear] < target:
                front+=1
            elif numbers[front] + numbers[rear] == target:
                ans=[]
                ans.append(front+1)
                ans.append(rear+1)
                return ans