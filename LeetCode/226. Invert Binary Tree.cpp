/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        TreeNode* lefty = root->left;
        TreeNode* righty = root->right;
        root->left = invertTree(righty);
        root->right = invertTree(lefty);
        return root;
    }
    
};