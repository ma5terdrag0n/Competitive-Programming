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
    
    bool equals(TreeNode* s, TreeNode* t){
        if(!s && !t){
            return 1;
        }
        if(s == NULL || t == NULL){
            return 0;
        }
        return (s->val == t->val) && equals(s->left, t->left) && equals(s->right, t->right);
    }
    
    bool isSubtree1(TreeNode* s, TreeNode* t, bool x, TreeNode* original) {
        if(s==NULL && t)return 0;
        return equals(s, t) || isSubtree1(s->left, original, 0, original) || isSubtree1(s->right, original, 0, original); 
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t){
        return isSubtree1(s, t, 0, t);
    }
};
