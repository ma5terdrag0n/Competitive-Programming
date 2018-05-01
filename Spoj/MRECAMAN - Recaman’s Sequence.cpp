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

void solve(){
    ll a[512345] = {0};
    a[0] = 0;
    set<ll> s;
    s.insert(0);
    for(int i = 1 ; i < 500001 ; i ++){
        ll x = a[i - 1] - i;
        if(x > 0 and !s.count(x)){
            a[i] = x;
        }else{
            a[i] = x + i + i;
        }
        s.insert(a[i]);
    }
    // for(int i = 0 ; i < 10 ; i ++){
    //     cerr << a[i] << " ";
    // }
    // cout << endl;
    ll q;
    while(cin >> q and q != -1){
        cout << a[q] << "\n";
    }
}


int main(){solve();}
