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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        deque<TreeNode*> q1, q2;
        int which = 0;
        if(root == NULL){
            return v;
        }
        q1.push_back(root);
        while(!q1.empty() || !q2.empty()){
            bool ok = 0;
            if(!q1.empty()){
                while(!q1.empty()){
                    if(!ok){
                        v.push_back(q1.front()->val);
                        ok=1;
                    }
                    if(q1.front()->right){
                        q2.push_back(q1.front()->right);
                    }
                    if(q1.front()->left){
                        q2.push_back(q1.front()->left);
                    }
                    q1.pop_front();
                }
            }else if(!q2.empty()){
                while(!q2.empty()){
                    if(!ok){
                        v.push_back(q2.front()->val);
                        ok=1;
                    }
                    if(q2.front()->right){
                        q1.push_back(q2.front()->right);
                    }
                    if(q2.front()->left){
                        q1.push_back(q2.front()->left);
                    }
                    q2.pop_front();
                }
            }
        }
        return v;
    }
};
