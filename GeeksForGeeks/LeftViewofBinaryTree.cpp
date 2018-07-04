
void helper(Node* root, int currdepth ,int& maxdepth){
    if(root == NULL)return;
    if(maxdepth < currdepth){
        maxdepth = currdepth;
        cout << root->data << " ";
    }
    helper(root->left, currdepth+1, maxdepth);
    helper(root->right, currdepth+1, maxdepth);
    return;
}

void leftView(Node *root)
{
   // Your code here
   int minusone=-1;
   helper(root, 0, minusone);
}
