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
#define clr(a) memset(a, 0, sizeof(a))
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
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a+n
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

ll n, m;
map<string , vector<string> > adj;
map<string, ll> color;
map<string, ll> dfs_low, dfs_num;
ll counter = 0;
vector<string> s;

void dfs(string u){
    s.pb(u);
    color[u] = 1;
    dfs_low[u] = dfs_num[u] = counter++;
    rep(sz(adj[u])){
        string v = adj[u][i];
        if(dfs_num[v] == -1){
            dfs(v);
        }
        if(color[v] == 1)
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    // cout << u << " " << dfs_num[u] << " " << dfs_low[u] << endl;

    if(dfs_low[u] == dfs_num[u]){
        // Root of strongly connected component
        while(1){
            string v = s.back();
            s.pop_back();
            color[v] = 0;
            if(u == v){
                cout << v << endl;
                break;
            }
            cout << v << ", ";
        }
    }
}

void reset(){
    adj.clear();
    color.clear();
    dfs_num.clear();
    dfs_low.clear();
}

void solve(){
    ll cas = 0;
    ll fir = 1;
    while(cin >> n >> m and n && m){
        if(fir){
            fir = 0;
        }else{
            cout << endl;
        }
        reset();
        vector<string> names;
        set<string> done;
        rep(m){
            string x, y;
            cin >> x >> y;
            adj[x].pb(y);
            if(!done.count(x))names.pb(x);
            done.insert(x);
            if(!done.count(y))names.pb(y);
            done.insert(y);
        }
        rep(sz(names)){
            dfs_num[names[i]] = dfs_low[names[i]] = -1;
            color[names[i]] = 0;
        }
        cout << "Calling circles for data set "<<++cas<<":\n";        
        rep(sz(names)){
            if(dfs_num[names[i]] == -1){
                dfs(names[i]);
            }
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










