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
    ll t;
    cin >> t;
    ll counter = 1;
    while(t--){
        ll n;
        cin >> n;
        ll a[n];
        rep(i,n){
            cin >> a[i];
        }
        ll energy = 0;
        ll sum = 0;
        for(int i = 0 ;i < n ; i ++){
            sum += a[i];
            if(sum <= 0){
                energy -= sum;
                sum = 0;
            }
        }
        cout << "Scenario #" << counter++ << ": ";
        cout << energy + 1 << endl;
    }
}


int main(){
    // int start = clock();
    freopen("input.in" , "r" , stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    // cout << n;
    // int stop = clock();
    // cout << (stop - start) / 1000.0000<< endl;
}
