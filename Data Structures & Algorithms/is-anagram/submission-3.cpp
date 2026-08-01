class Solution {
public:
    bool isAnagram(string s, string t){
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char,int> hash_table1,hash_table2;

        for(char c:s){
            hash_table1[c]++;
        }
        for(char c:t) {
            hash_table2[c]++;
        }

        return hash_table1 == hash_table2;
    }
};