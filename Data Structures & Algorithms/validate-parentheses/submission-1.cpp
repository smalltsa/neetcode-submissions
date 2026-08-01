#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        
        // 如果長度是奇數，絕對不可能完全配對
        if (s.size() % 2 != 0) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            
            // 遇到左括號，直接推入堆疊
            if (c == '(' || c == '[' || c == '{') {
                temp.push(c);
            } 
            // 遇到右括號，進行配對檢查
            else if (c == ')' || c == ']' || c == '}') {
                // 防禦機制：若此時堆疊已空，說明右括號比左括號多，不合法
                if (temp.empty()) {
                    return false;
                }
                
                // 取出堆疊頂端的左括號
                char top_char = temp.top();
                temp.pop();
                
                // 檢查是否精準配對
                if ((c == ')' && top_char != '(') ||
                    (c == ']' && top_char != '[') ||
                    (c == '}' && top_char != '{')) {
                    return false;
                }
            }
        }
        
        // 確保所有左括號都有找到伴（堆疊必須完全清空）
        return temp.empty();
    }
};