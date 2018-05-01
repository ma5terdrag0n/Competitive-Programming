#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define inf 1000000007
#define fr first
#define sc second
#define eps 1e-15
#define sni(x) scanf("%d",&x)
#define snl(x) scanf("%lld", &x)
#define snc(x) scanf("%c", &c);
#define rep(i, n) for(int i = 0 ; i < n ;i ++)
#define FOR(i, x, y) for(int i = x ; i < y ; i ++)
#define DEC(i, x, y) for(int i = x ; i >= y ; i --)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
bool isLower(char c){
    return (c <= 'z' and c >= 'a');
}

template<typename c>
int binary_search(c *a, int lo, int hi, c key){
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(a[mid] == key){
            return mid;
        }else if(a[mid] < key){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return -1;
}

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int fun(pair<int, int> p1, pair<int, int > p2){
    return (p1.sc >= p2.fr);
} 

string toLowerCase(string s){
    rep(i, s.size()){
        if(!isLower(s[i])){
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}

struct node
{
    /* data */
    node * left, * right;
    ll data;
};

node *newNode(){
    node *n = new node();
    n->left = n->right = NULL;
    n->data = -1;
    return n;
}

node * insert(node * root, int value) {
    if(root == NULL){
        node *N = new node();
        N->data = value;
        N->left = N->right = NULL;
        root = N;
    }
    else if(root->data > value){
        root->left = insert(root->left, value);
    }else{
        root->right = insert(root->right, value);
    }
   return root;
}

void preOrder(node *root){
    if(root == NULL)return;
    if(root->data != -1)
    cout << " " << root->data ;
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(node *root){
    if(root == NULL)return;
    inOrder(root->left);
    if(root->data != -1)
    cout << " " << root->data ;
    inOrder(root->right);
}
void postOrder(node *root){
    if(root == NULL)return;
    postOrder(root->left);
    postOrder(root->right);
    if(root->data != -1)
    cout << " " << root->data ;
}

void solve(){
    ll n;
    cin >> n;
    ll a[n];
    node *root = newNode();
    rep(i,n){
        cin >> a[i];
        insert(root, a[i]);
    }
    cout << "Pre order :"; 
    preOrder(root);
    cout << endl;
    cout << "In order  :";
    inOrder(root);
    cout << endl;
    cout << "Post order:" ;
    postOrder(root);
    cout << endl;
}

int main(){
    solve();
}
