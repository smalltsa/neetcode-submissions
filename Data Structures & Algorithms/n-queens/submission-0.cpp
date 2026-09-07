class Solution {
public:
    vector<vector<string>> ans;

    unordered_set<int> cols;      // 哪些 column 已有皇后
    unordered_set<int> diag1;     // row - col
    unordered_set<int> diag2;     // row + col

    void dfs(int row, int n, vector<string>& board) {

        // 每一列都成功放完
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // 嘗試這一列的每個 column
        for (int col = 0; col < n; col++) {

            // 這格會被其他皇后攻擊
            if (cols.count(col) ||
                diag1.count(row - col) ||
                diag2.count(row + col)) {
                continue;
            }

            // choose
            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            // 下一列
            dfs(row + 1, n, board);

            // backtrack
            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        dfs(0, n, board);

        return ans;
    }
};