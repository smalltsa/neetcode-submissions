class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        for (string str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());  // Sort characters in the string
            anagramGroups[sortedStr].push_back(str);  // Group anagrams using the sorted string as a key
        }
        
        vector<vector<string>> ans;
        for (auto& pair : anagramGroups) {
            ans.push_back(pair.second);  // Collect grouped anagrams
        }
        
        return ans;
    }
};
