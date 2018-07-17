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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > v;
        if(!root)return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*> tmp;
            vector<int> temp;
            while(!q.empty()){
                if(q.front()->left){
                    tmp.push(q.front()->left);
                }
                if(q.front()->right){
                    tmp.push(q.front()->right);
                }
                temp.push_back(q.front()->val);
                q.pop();
            }
            v.push_back(temp);
            while(!tmp.empty()){
                q.push(tmp.front());
                tmp.pop();
            }
        }
        return v;
        
    }
};
