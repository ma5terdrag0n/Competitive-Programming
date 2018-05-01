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

void solve(){
    ll n, k, mod = 10000007;
    while(cin >> n >> k and n && k){
        ll x = 2LL * modpow(n - 1, k, mod) % mod;
        ll y = 2LL * modpow(n - 1, n - 1, mod) % mod;
        ll z = modpow(n, n, mod) % mod;
        ll w = modpow(n, k, mod) % mod;
        x = (x + mod) % mod;
        y = ( y + mod) % mod;
        z = (z + mod )% mod;
        w = (w + mod) % mod;
        cout << ((((x + y) % mod + z) % mod + w) % mod + mod) % mod << endl;
    }

}

int main(){
    solve();
}
