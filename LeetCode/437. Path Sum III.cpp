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
    
    int ans(TreeNode* root, int sum){
        if(root == NULL)return 0;
        int ret = 0;
        if(sum - root->val == 0){
            ret++;
        }
        return ret + ans(root->left, sum-root->val) + ans(root->right, sum-root->val); 
        
        
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL){
            return 0;
        }
        return pathSum(root->left, sum) + pathSum(root->right, sum) + ans(root, sum);
    }
};
