class Solution {
public:
    int dfs(TreeNode* root, int maxSoFar) {
        if (!root)
            return 0;

        int good = 0;

        if (root->val >= maxSoFar)
            good = 1;

        maxSoFar = max(maxSoFar, root->val);

        return good
            + dfs(root->left, maxSoFar)
            + dfs(root->right, maxSoFar);
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};