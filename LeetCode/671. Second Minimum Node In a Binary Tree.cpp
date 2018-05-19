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
    
    void findSecondMinimumValueUtil(TreeNode* root, int& first, int& second){
        if(root == NULL){
            return;
        }    
        int data = root->val;
        if(data < first){
            second = first;
            first = data;
        }else if(data < second && data > first){
            second = data;
        }
        findSecondMinimumValueUtil(root->left, first, second);
        findSecondMinimumValueUtil(root->right, first, second);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int first = INT_MAX;
        int second = INT_MAX;
        findSecondMinimumValueUtil(root, first, second);
        if(second == INT_MAX){
            return -1;
        }
        return second;
    }
    
};
