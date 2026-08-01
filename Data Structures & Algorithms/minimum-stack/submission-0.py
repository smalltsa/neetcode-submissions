class MinStack:
    def __init__(self):
        self.stack = []  # 正常的數值棧
        self.minStack = []  # 儲存當前最小值的輔助棧

    def push(self, val: int) -> None:
        self.stack.append(val)
        # 如果 minStack 為空，或者 val 小於等於 minStack 的頂部，則推入
        if not self.minStack or val <= self.minStack[-1]:
            self.minStack.append(val)

    def pop(self) -> None:
        if self.stack:
            popped = self.stack.pop()
            # 如果移除的數值剛好是最小值，也要同步從 minStack 移除
            if popped == self.minStack[-1]:
                self.minStack.pop()

    def top(self) -> int:
        if self.stack:
            return self.stack[-1]
        return -1  # 或者丟出例外

    def getMin(self) -> int:
        if self.minStack:
            return self.minStack[-1]
        return -1  # 或者丟出例外
