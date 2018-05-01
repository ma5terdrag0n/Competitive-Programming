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
const ll N = 1000000;
ll st[N << 4];
ll a[N], n , k;

void create(ll lo, ll hi, ll seg){
    if(lo == hi){
        st[seg] = a[lo];
        return;
    }
    ll mid = (lo + hi) / 2;
    create(lo, mid, seg * 2 );
    create(mid + 1, hi, seg * 2 + 1);
    st[seg] = st[seg * 2 + 1] & st[seg * 2];
}

ll query(ll lo, ll hi, ll seg, ll qlo, ll qhi){
    if(qlo == lo and qhi == hi){
        return st[seg];
    }
    ll mid = (lo + hi) / 2;
    ll left = seg * 2;
    ll right = seg * 2 + 1;
    if(qhi <= mid){
        return query(lo, mid, left, qlo, qhi);
    }else if(qlo > mid){
        return query(mid + 1, hi, right, qlo, qhi);
    }
    return query(lo, mid, left, qlo, mid) & query(mid + 1, hi, right, mid + 1, qhi);
}

void reset(){
    memset(a, 0, sizeof a);
    memset(st, 0, sizeof st);
}

void solve(){
    ll t;
    cin >> t;
    while(t--){
        // reset();
        cin >> n >> k;
        k = min(k, n - 1);
        rep(i,n){
            cin >> a[i];
        }
        create(0,n - 1, 1);
        for(int i = 0 ; i < n ; i ++){
            ll s = (i - k + n) % n;
            ll e = (i + k) % n;
            ll res = -1;
            if(s < i) res &= query(0LL, n - 1, 1LL, s, i);
            else res &= query(0LL, n - 1, 1LL, 0LL, i) & query(0LL, n - 1, 1LL, s, n - 1);
            if(e > i) res &= query(0LL, n - 1, 1LL, i, e);
            else res &= query(0LL, n - 1,  1LL, i, n - 1) & query(0LL, n - 1, 1LL, 0LL, e);
            if(i) cout << " ";
            cout << res;
        }
        cout << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    solve();
}
