// Serialization converts the tree into a vector
// Deserialization converts an array into a tree

void serialize2(Node *root,vector<int> &A,int pos)
{
    //Your code here
    if(root == NULL)return;
    if(A.size() < pos+1)
        A.resize(pos+1);
    A[pos] = root->data;
    serialize2(root->left, A, pos*2+1);
    serialize2(root->right, A, pos*2+2);
    
}

void serialize(Node *root,vector<int> &A){
    serialize2(root, A, 0);
}


/*this function deserializes
 the serialized vector A*/
Node * deSerialize2(vector<int> &A, int index)
{
   //Your code here
   if(index >= A.size() || A[index] == 0)return NULL;
   Node* node = (Node*) malloc(sizeof(Node*));
   node->data = A[index];
   node->left = deSerialize2(A, index*2+1);
   node->right = deSerialize2(A, index*2+2);
   return node;
}

Node * deSerialize(vector<int> &A){
    return deSerialize2(A, 0);
}
