class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        
        freq1 = [0] * 26
        freq2 = [0] * 26
        a_ord = ord('a')

        for i in range(len(s1)):
            freq1[ord(s1[i]) - a_ord] += 1
            freq2[ord(s2[i]) - a_ord] += 1
        
        if freq1 == freq2:
            return True

        for i in range(len(s1),len(s2)):
            freq2[ord(s2[i]) - a_ord] += 1
            freq2[ord(s2[i - len(s1)])- a_ord] -= 1

            if freq1 == freq2:
                return True
        return False 