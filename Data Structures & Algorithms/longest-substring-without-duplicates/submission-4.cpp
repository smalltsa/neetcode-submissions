class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0,max_len = 0;

        for(int right = 0;right < s.size();right++){
            while(window.count(s[right])){
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            max_len = max(max_len,right - left + 1);
        }
        return max_len;
    }
};
