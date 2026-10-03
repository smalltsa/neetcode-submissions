class Solution {
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";   // 如果這個節點是某單字的結尾，就存那個單字
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // 1. 建 Trie
        TrieNode* root = new TrieNode();
        for (const string& w : words) {
            TrieNode* node = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!node->children[idx]) node->children[idx] = new TrieNode();
                node = node->children[idx];
            }
            node->word = w;
        }

        // 2. 從每一格出發 DFS
        vector<string> result;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                dfs(board, i, j, root, result);
        return result;
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* parent, vector<string>& result) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;

        char c = board[i][j];
        if (c == '#' || !parent->children[c - 'a']) return;  // 走過了，或 Trie 沒這條路

        TrieNode* node = parent->children[c - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word.clear();   // 清掉，避免同一個單字被重複加入
        }

        board[i][j] = '#';        // 標記為已使用
        dfs(board, i + 1, j, node, result);
        dfs(board, i - 1, j, node, result);
        dfs(board, i, j + 1, node, result);
        dfs(board, i, j - 1, node, result);
        board[i][j] = c;          // 回溯：還原
    }
};