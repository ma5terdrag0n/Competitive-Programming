bool helper(Node* root1, Node* root2){
    if(!root1 && !root2){
        return 1;
    }
    if(!root1 || !root2)return 0;
    bool a = (root1->key == root2->key);
    bool b = helper(root1->left, root2->right);
    bool c = helper(root1->right, root2->left);
    return a and b and c;
}

bool isSymmetric(struct Node* root)
{
	// Code here
	return helper(root, root);
}
