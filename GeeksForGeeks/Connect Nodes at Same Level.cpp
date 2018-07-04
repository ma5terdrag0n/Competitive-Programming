/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */
// Should set the nextRight for all nodes
void connect(Node *p)
{
   // Your Code Here
   queue<Node* > q, tmp;
   if(p == NULL)return;
   q.push(p);
   while(!q.empty()){
       Node* last = NULL;
       while(!q.empty()){
            Node* foo = q.front();
            q.pop();
            if(foo->left)
                tmp.push(foo->left);
            if(foo->right)
                tmp.push(foo->right);
            if(last){
                last->nextRight = foo;
            }
            last = foo;
            last->nextRight = NULL;
       }
       while(!tmp.empty()){
           q.push(tmp.front());
           tmp.pop();
       }
   }
}
