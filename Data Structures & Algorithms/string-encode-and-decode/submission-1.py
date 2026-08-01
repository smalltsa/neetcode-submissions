class Solution:

    def encode(self, strs: List[str]) -> str:
        new_str = ""
        for i in strs:
            new_str = new_str + i+'屌'
        return new_str
    def decode(self, s: str) -> List[str]:
        result = s.split("屌")
        result.pop()
        return result