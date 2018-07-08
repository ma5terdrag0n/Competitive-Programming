// To check if the value of a node = sum of nodes of left subtree and right subtree
int helper(Node* root){
    if(root == NULL)return 0;
    if(root->left == NULL && root->right == NULL)return root->data;
    int leftsum = helper(root->left);
    int rightsum = helper(root->right);
    if(root->data != leftsum + rightsum || leftsum == -1 || rightsum == -1)return -1;
    return root->data*2;
}

bool isSumTree(Node* root)
{
    if(root == NULL)return 1;
     // Your code here
     if(helper(root) == -1)return 0;
     return 1;
}
