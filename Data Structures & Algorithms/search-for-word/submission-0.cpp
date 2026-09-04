class Solution {
public:
    bool dfs(vector<vector<char>>& board,
             const string& word,
             int index, int i, int j) {

        int rows = board.size();
        int cols = board[0].size();

        // 剪枝 1：超出邊界
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            return false;
        }

        // 剪枝 2：目前字元不符合
        if (board[i][j] != word[index]) {
            return false;
        }

        // 最後一個字元也匹配，成功
        if (index == word.size() - 1) {
            return true;
        }

        // 暫時標記，避免同一格在目前路徑中被重複使用
        char original = board[i][j];
        board[i][j] = '#';

        bool found =
            dfs(board, word, index + 1, i + 1, j) ||
            dfs(board, word, index + 1, i - 1, j) ||
            dfs(board, word, index + 1, i, j + 1) ||
            dfs(board, word, index + 1, i, j - 1);

        // Backtracking：恢復現場
        board[i][j] = original;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};