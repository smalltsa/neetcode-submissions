class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        s_dict = {}
        t_dict = {}
        
        for i in s:
            s_dict[i] = s_dict.get(i, 0) + 1  # 設定預設值 0
        
        for i in t:
            t_dict[i] = t_dict.get(i, 0) + 1
        
        return s_dict == t_dict  # 比較兩個字典
