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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        node->val = 0;
        TreeNode *left1, *right1, *left2, *right2;
        left1 = right1 = left2 = right2 = NULL;
        if(t1){
            node->val += t1->val;
            left1 = t1->left;
            right1 = t1->right;
        }
        
        if(t2){
            node->val += t2->val;
            left2 = t2->left;
            right2 = t2->right;
        }
        if(t1 == NULL and t2 == NULL){
            return NULL;
        }
        node->left = mergeTrees(left1, left2);
        node->right = mergeTrees(right1, right2);
        return node;
        
    }
};
