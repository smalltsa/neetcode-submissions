class Solution:
    def isValid(self, s: str) -> bool:
        stack1 = []
        mapping = {')': '(', '}': '{', ']': '['}
        
        for i in s:
            if i in mapping:  # 遇到閉合括號
                if stack1 and stack1[-1] == mapping[i]:  
                    stack1.pop()  # 匹配成功，移除左括號
                else:
                    return False  # 不匹配
            else:
                stack1.append(i)  # 遇到左括號，入棧
        
        return not stack1  # 若 stack1 為空，則括
