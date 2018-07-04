struct Node {
    int data;
    Node * right, * left;
};*/
/*You are required to complete
this function*/
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(!root)return NULL;
   if(root->data > n1 && root->data > n2){
       return LCA(root->left, n1, n2);
   }
   if(root->data < n1 && root->data < n2){
       return LCA(root->right, n1, n2);
   }
   return root;
}
