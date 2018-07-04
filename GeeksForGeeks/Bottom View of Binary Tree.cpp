map<int, int> m;

void helper(Node* root, int start){
    if(!root)return;
    m[start] = root->data;
    helper(root->left, start-1);
    helper(root->right, start+1);
}

void bottomView(Node *root)
{
    m.clear();
   // Your Code Here
   helper(root, 0);
   for(map<int, int>::iterator it = m.begin() ; it!=m.end() ;it++){
       cout << it->second << " ";
   }
}
