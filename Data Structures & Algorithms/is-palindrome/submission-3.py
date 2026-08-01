class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        new = [w for w in s if w.isalnum()]  # isalnum() 保留字母和數字

        i, j = 0, len(new) - 1
        while j >= i:
            if new[j] != new[i]:
                return False  # 不需要 check 變數，直接 return False
            j -= 1
            i += 1
        return True