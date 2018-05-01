// *
// *
// *  Created By : Pritish Thakkar 
// *  Hackerrank : ma5terdrag0n
// *  CodeChef : solo_loser
// *  Hackerearth : pritish9
// *------------------------------------
// *  OS : Ubuntu 16.04
// *  Language : CPP14
// *  Editor : Sublime Text 3
// *  C++ compiler : g++
// *
// *
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define inf 1000000007
#define fr first
#define sc second
#define eps 1e-9
#define sz(x) x.size()
#define sni(x) scanf("%d",&x)
#define snl(x) scanf("%lld", &x)
#define snc(x) scanf("%c", &c);
#define rep(n) for(int i = 0 ; i < n ;i ++)
#define repc(i, n) for(int i = 0 ; i < n ; i ++)
#define FOR(i, x, y) for(int i = x ; i < y ; i ++)
#define DEC(i, x, y) for(int i = x ; i >= y ; i --)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b,c))
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

bool isUpper(char c) {return (c >= 'A' && c <= 'Z');}
bool isLower(char c) {return (c >= 'a' && c <= 'z');}
bool iplpha(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z');}
bool isnum(char c){return (c >= '0' and c <= '9');}
bool isalnum(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z')||(c >= '0' && c <= '9');}
char toUpper(char c){return isUpper(c)?c:c-'a'+'A';}
char toLower(char c){return isLower(c)?c:c+'a'-'A';}
bool isvowel(char c){c = toLower(c); return (c == 'a' or c == 'e' or c == 'i' or c == 'i' or c == 'o' or c == 'u');}
template<typename t> t gcd(t a, t b){return ((b == 0) ? a : gcd(b, a%b));} 
template<typename t> t lcm(t a, t b){return (a * (b / gcd(a, b)));}
template <typename T> T modpow(T base, T exp, T modulus) {base %= modulus;T result = 1;while (exp > 0) {if (exp & 1) result = (result * base) % modulus;base = (base * base) % modulus;exp >>= 1;}return result;}
string toLowerCase(string s){rep(s.size()){if(!isLower(s[i])){s[i] = toLower(s[i]);}}return s;}
string toUpperCase(string s){rep(s.size()){s[i] = toUpper(s[i]);}return s;}
template<typename T> void cumulative(T *a, T *b, T n){rep(n){i ? b[i] = b[i-1] + a[i] : b[i] = a[i];}}
bool ispal(string s){ll lo, hi;lo = 0;hi = s.length()-1;while(lo <= hi){if(s[lo] != s[hi]){return 0;}lo++;--hi;}return 1;}
template<class T >string toString(T n){string v = "";while(n){v.pb(n % 10 + '0');n /= 10;}reverse(all(v));return v;}

//--------------------------------------------------------------------
//we will also make an additional array, let's call it lazy array. 
//This array will help us to update our buckets. 

void build(ll *st, ll *a, ll n, ll lo, ll hi, ll idx){
    if(lo == hi){
        st[idx] = a[lo];
        return;
    }
    ll mid = (lo + hi) >> 1;
    build(st, a, n, lo, mid, idx << 1);
    build(st, a, n, mid+1, hi, idx << 1|1);
    st[idx] = min(st[idx << 1] , st[idx << 1|1]);
}

ll query(ll *st, ll *a, ll n, ll lo, ll hi, ll idx, ll left, ll right){
    if(left > hi or right < lo){
        return inf;
    }
    if(left <= lo and right >= hi){
        return st[idx];
    }
    ll mid = (lo + hi) >> 1;
    if(right <= mid){
        return query(st, a, n, lo, mid, idx << 1, left, right);
    }else if(left > mid){
        return query(st, a, n, mid+1, hi, idx << 1 | 1, left, right);
    }
    return min(query(st, a, n, lo, mid, idx << 1, left, right)\
        ,query(st, a, n, mid+1, hi, idx << 1 | 1, left, right));
}

void solve(){
    ll t;
    cin >> t;
    ll cas = 0;
    while(t--){
        ll n, q;
        cin >> n >> q;
        ll a[n];
        rep(n){
            cin >> a[i];
        }

        ll st[n << 4];
        build(st, a, n, 0, n-1, 1);
        cout << "Scenario #" << ++cas << ":\n";
        while(q--){
            ll left, right;
            cin >> left >> right;
            left--;
            right--;
            cout << query(st, a, n, 0, n-1, 1, left, right) << endl;
        }

    }
}

int main(){
    std::ios::sync_with_stdio(0);
    // int start = clock();
    #ifdef ONLINE_JUDGE
    #else
      freopen("input.in" , "r" , stdin);
      // freopen("output.txt", "w", stdout);
    #endif
    solve();
    // cout << n;
    // int stop = clock();
    // cout << (stop - start) / 1000.0000<< endl;
}










