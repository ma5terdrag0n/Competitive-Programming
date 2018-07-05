int countLeaves(Node* root)
{
  // Your code here
  if(root == NULL)return 0;
  if(!root->left && !root->right)return 1;
  return countLeaves(root->left) + countLeaves(root->right);
}
