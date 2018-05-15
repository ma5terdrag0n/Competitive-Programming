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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ret;
        deque<TreeNode*> q1, q2;
        int which = 0;
        if(root == NULL){
            return ret;
        }
        q1.push_back(root);
        int counter = 0;
        while(!q1.empty() || !q2.empty()){
            vector<int> v;
            if(!q1.empty()){
                while(!q1.empty()){
                    v.push_back(q1.front()->val);
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
                    v.push_back(q2.front()->val);
                    if(q2.front()->right){
                        q1.push_back(q2.front()->right);
                    }
                    if(q2.front()->left){
                        q1.push_back(q2.front()->left);
                    }
                    q2.pop_front();
                }
                
            }
            if(counter%2==0){
                reverse(v.begin(), v.end());
            }
            counter++;
            ret.push_back(v);
        }
        return ret;
    }
};
