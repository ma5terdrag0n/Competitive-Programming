int height(Node* node)
{
   // Your code here
   if(node == NULL)return 0;
   return max(height(node->left), height(node->right)) + 1;
}
