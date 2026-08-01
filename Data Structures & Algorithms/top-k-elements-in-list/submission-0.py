class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        s_dict = {}
        for i in nums:
            s_dict[i] = s_dict.get(i, 0) + 1
        sorted_items = sorted(s_dict.items(), key=lambda x: x[1],reverse=True)
        ans = []
        sorted_keys = [key for key, _ in sorted_items]
        for i in range(k):
            ans.append(sorted_keys[i])
        return ans
