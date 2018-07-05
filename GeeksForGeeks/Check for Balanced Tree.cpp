int helper(Node* root){
    if(root == NULL)return 0;
    int lefty = helper(root->left);
    int righty = helper(root->right);
    if(lefty == -1 || righty == -1 || abs(righty - lefty) > 1)return -1;
    return max(lefty, righty) + 1;
}

bool isBalanced(Node *root)
{
    //  Your Code here
    int x = helper(root);
    if(x == -1)return 0;
    return 1;
    
}
