class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };

    TrieNode* root;

    bool dfs(const string& word, int i, TrieNode* node) {
        if (!node) return false;
        if (i == word.size()) return node->isEnd;

        char c = word[i];
        if (c == '.') {
            // 萬用字元：嘗試每一個存在的子節點
            for (int k = 0; k < 26; k++) {
                if (node->children[k] && dfs(word, i + 1, node->children[k]))
                    return true;
            }
            return false;
        }
        return dfs(word, i + 1, node->children[c - 'a']);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};