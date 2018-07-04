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
    
    int helper(TreeNode* root, int& ans){
        if(root == NULL)return 0;
        if(root->left == NULL && root->right == NULL){
            ans = max(ans, 0);
            return 1;
        }
        int maxLeft = helper(root->left, ans);
        int maxRight = helper(root->right, ans);
        ans = max(maxLeft + maxRight, ans);
        return max(maxLeft, maxRight)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root ==NULL){
            return 0;
        }
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};
