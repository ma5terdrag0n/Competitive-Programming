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
typedef vector<ii> vii;

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
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll a[n], lo, hi, maxi;
        lo = hi = 0;
        rep(i,n){
            cin >> a[i];
            hi = max(hi, a[i]);
        }
        maxi = hi;
        sort(a, a + n);
        ll ans = 0;
        while(lo <= hi){
            ll mid = (lo + hi) / 2;
            ll cov = 0;
            ll d = 0, x;
            while((x = upper_bound(a, a + n, d)-a) != n){
                cov++;
                d = a[x] + mid - 1;
            }
            // cerr << mid << " " << cov << endl; 
            if(cov >= m){
                lo = mid + 1;
                ans = max(ans, mid);
            }else{
                hi = mid - 1;
            }
        }   
        cout << ans << endl;
    }    
}


int main(){
    std::ios::sync_with_stdio(0);
    freopen("input.in" , "r" , stdin);
    solve();
}
