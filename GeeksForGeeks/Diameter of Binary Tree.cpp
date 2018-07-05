int ans = 0;

int helper(Node* node){
    if(node == NULL)return 0;
    int a1 = helper(node->left);
    int a2 = helper(node->right);
    ans = max(ans, a1+a2+1);
    return max(a1,a2)+1;
}

int diameter(Node* node)
{
   // Your code here
   ans = 0;
   helper(node);
   return ans;  
}
