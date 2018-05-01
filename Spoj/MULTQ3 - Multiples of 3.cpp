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


ll n, q;
const int N = 100011 << 4;
ll st[N][3] = {0}, lazy[N] = {0};

void build(ll lo, ll hi, ll idx){
    if(lo == hi){
        st[idx][0] = 1;
        st[idx][1] = st[idx][2] = 0;
        return;
    }
    ll mid = (lo + hi) >> 1;
    build(lo, mid, idx << 1);
    build(mid+1, hi, idx << 1|1);
    st[idx][0] = st[idx << 1][0] + st[idx << 1|1][0];
    st[idx][1] = st[idx][2] = 0;
}

void update(ll lo, ll hi, ll idx, ll left, ll right){
    // cout << lo << " " << hi << " " << left << " " << right << endl;
    

    if(lazy[idx] != 0){
        if(lazy[idx] == 1){
            swap(st[idx][0],st[idx][1]);
            swap(st[idx][0],st[idx][2]);
        }else if(lazy[idx] == 2){
            swap(st[idx][2],st[idx][1]);
            swap(st[idx][0],st[idx][2]);
        }

        if(lo != hi){
            lazy[idx << 1] = (lazy[idx << 1] + lazy[idx]) % 3;
            lazy[idx << 1|1] = (lazy[idx] + lazy[idx << 1|1])% 3;
        }
        lazy[idx] = 0;
    }
    
    if(right < left || left > hi || lo > right){
        return;
    }

    if(left <= lo and right >= hi){
        swap(st[idx][0],st[idx][1]);
        swap(st[idx][0],st[idx][2]);
        if(lo != hi){
            lazy[idx*2] = (1 + lazy[idx << 1]) % 3;
            lazy[idx*2+1] = (1 + lazy[idx*2+1]) % 3;
        }
        return;
    }
    ll mid = (lo + hi) >> 1;
    update(lo, mid, idx << 1, left, right);
    update(mid+1, hi, idx << 1|1, left, right);    
    rep(3){
        st[idx][i] = st[idx*2][i] + st[idx*2+1][i];
    }
}

ll query(ll lo, ll hi, ll idx, ll left, ll right){
    if(lazy[idx] != 0){
        if(lazy[idx] == 1){
            swap(st[idx][0],st[idx][1]);
            swap(st[idx][0],st[idx][2]);
        }
        if(lazy[idx] == 2){
            swap(st[idx][2],st[idx][1]);
            swap(st[idx][0],st[idx][2]);
        }
        if(lo != hi){
            lazy[idx << 1] = (lazy[idx << 1] + lazy[idx]) % 3;
            lazy[idx << 1|1] = (lazy[idx] + lazy[idx << 1|1])% 3;
        }
        lazy[idx] = 0;
    }
    if(left > hi or right < lo){
        return 0;
    }
    if(left <= lo and right >= hi){
        return st[idx][0];
    }
    ll mid = (lo + hi) >> 1;
    return query(lo, mid, idx << 1, left, right)+query(mid+1, hi, idx << 1|1, left, right);
}

void solve(){
    cin >> n >> q;
    build(0, n-1, 1);
    while(q--){
        ll type;
        cin >> type;
        ll left, right;
        if(type == 1){
            cin >> left >> right;
            // cout << "ERROR\n";
            cout << query(0, n-1, 1, left, right) << endl;
        }else{
            cin >> left >> right;
            // cout << "EXCEPTION\n";
            update(0, n-1, 1, left, right);
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










