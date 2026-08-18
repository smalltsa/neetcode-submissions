/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int val1,val2;
        if(root==nullptr){
            return 0;
        }
        val1=maxDepth(root->left);
        val2=maxDepth(root->right);
        if(val1>val2){
            return (val1+1);
        }else{
            return( val2+1 );
        }
    }
};
