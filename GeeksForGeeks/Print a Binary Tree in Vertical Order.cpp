
map<int, vector<int> > m;

void helper(Node* root, int start){
    if(!root)return;
    m[start].push_back(root->data);
    helper(root->left, start-1);
    helper(root->right, start+1);
}

   
void verticalOrder(Node *root)
{
    m.clear();
    helper(root, 0);
    for(map<int, vector<int> > :: iterator it = m.begin() ; it != m.end() ; it++){
        int v = it->first;
        sort(m[v].begin(), m[v].end());
        for(int i = 0 ; i < m[v].size() ; i++){
            cout << m[v][i] << " ";
        }
        cout << "$";
    }
}
