int ans = 0;

int helper(Node* root){
    if(root == NULL)return 0;
    int a1, a2;
    a1 = helper(root->left);
    a2 = helper(root->right);
    ans = max(ans, a1 + a2 + root->data);
    return max(a1, a2) + root->data;
}

int maxPathSum(struct Node *root)
{
    //add code here.
    ans = 0;
    helper(root);
    return ans;
}
