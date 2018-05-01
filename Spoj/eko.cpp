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

//--------------------------------------------------------------------

void solve(){
    ll n, m;
    scanf("%lld%lld", &n , &m);
    ll a[n];
    ll mid, lo, hi;
    lo = 0, hi = 0;
    rep(i,n){
        scanf("%lld", &a[i]);
        if(hi < a[i]){
        	hi = a[i];
        }
    }
    ll ans = 0;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        ll ret = 0;
        rep(i,n){
            if(a[i] > mid){
                    ret += a[i] - mid;
            }
        }
        // cerr << mid << " " << res << endl;
        if(ret == m){
            ans = mid;
            break;
        }
        else if(ret > m){
            lo = mid + 1;
            if(ans < mid){
            	ans = mid;
            }
        }else{
            hi = mid - 1;
        }
    }
    printf("%lld\n" , ans);
}
int main(){
    solve();
}
