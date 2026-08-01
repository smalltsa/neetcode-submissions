from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        
        for token in tokens:
            if token.lstrip('-').isdigit():  # 檢查是否為數字（包含負數）
                stack.append(int(token))  # 轉換成整數
            else:
                num2 = stack.pop()
                num1 = stack.pop()
                
                if token == '+':
                    stack.append(num1 + num2)
                elif token == '-':
                    stack.append(num1 - num2)
                elif token == '*':
                    stack.append(num1 * num2)
                elif token == '/':
                    stack.append(int(num1 / num2))  
        
        return stack[0]  # 最後堆疊中只剩下一個結果
