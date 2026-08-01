class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_string = "";
        for (const string& s : strs) {
            // 長度 + 分隔號 + 字串本身
            encoded_string += to_string(s.length()) + "#" + s;
        }
        return encoded_string;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded_strs;
        int i = 0;
        while (i < s.length()) {
            // 尋找分隔符號 '#'
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            // 算出長度
            int len = stoi(s.substr(i, j - i));
            // 根據長度切出原始字串
            decoded_strs.push_back(s.substr(j + 1, len));
            // 移動指針到下一個字串的開頭
            i = j + 1 + len;
        }
        return decoded_strs;
    }
};