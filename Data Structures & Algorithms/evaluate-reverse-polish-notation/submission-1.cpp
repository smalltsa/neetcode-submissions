class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tmp;
        
        for (int i = 0; i < tokens.size(); i++) {
            // 判斷是否為運算子（使用雙引號的字串比對）
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                // 先取得最上層的兩個數字，再執行 pop()
                int a = tmp.top(); tmp.pop();
                int b = tmp.top(); tmp.pop();
                
                if (tokens[i] == "+") tmp.push(b + a);
                else if (tokens[i] == "-") tmp.push(b - a);
                else if (tokens[i] == "*") tmp.push(b * a);
                else if (tokens[i] == "/") tmp.push(b / a);
            } 
            else {
                // 如果是數字，用 stoi 將字串轉為整數後推入堆疊
                tmp.push(stoi(tokens[i]));
            }
        }
        // 最後堆疊中只會剩下一個最終結果
        return tmp.top();
    }
};