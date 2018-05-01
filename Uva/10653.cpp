/*
*  Author : pritish.thakkar 
*/

#include<bits/stdc++.h>
#define     pb                      push_back
#define     mkp                     make_pair
#define     inf                     1000000007
#define     rep(i,n)                for(int i=0;i<n;i++)
#define     fr                      first
#define     sc                      second
#define     clr(a)                  memset(a,0LL,sizeof a);
#define     pi                      3.141592653589793
#define     gc                      getchar
#define     all(v)                  v.begin(), v.end()
using       namespace               std;

typedef     unsigned long long      ull;
typedef     long long               ll;
typedef     vector<ll>              vi;
typedef     pair<ll,ll>             ii;
typedef     vector<ii>              vii;
typedef     set<ll>::iterator       sit;
typedef     map<ll,ll>::iterator    mit;
typedef     vector<int>::iterator   vit;

template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}

//_____________________________


ll gcd(ll a, ll b){return (b == 0) ? (a) : gcd(b, a%b);}
bool isUpper(char c) {return (c >= 'A' && c <= 'Z');}
bool isLower(char c) {return (c >= 'a' && c <= 'z');}
bool iplpha(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z');}
bool iplnum(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z')||(c >= '0' && c <= '9');}
char toUpper(char c){return isUpper(c)?c:c-'a'+'A';}
char toLower(char c){return isLower(c)?c:c+'a'-'A';}
template<typename t> t _GCD(t a, t b){return ((b == 0) ? a : _GCD(b, a%b));} 
template<typename t> t _LCM(t a, t b){return (a * (b / _GCD(a, b)));}
ll modpow(ll base, ll expo, ll mod){base  = base % mod;ll ret = 1LL;while(expo > 0){if(expo & 1LL){ret =( ret * base) % mod;}base = (base * base )% mod;expo >>= 1LL;}return ret;}

//______________________________

bool p[10000001];
vi primes;
void sieve(ll n){memset(p,1,sizeof p);p[0] = p[1] = 0;
    for(int i = 2 ; i <= sqrt(n) ; i++){if(p[i]){for(int j = i * i ; j < n ; j+=i){p[j] = 0;}}}
    for(int i = 2 ; i <= n ; i ++){if(p[i]){primes.pb(i);}}}

bool isPrime(ll n){if(n < 1000001){return p[n];}ll ans = 0;for(int i= 0 ; i < primes.size() && primes[i] * primes[i] <= n  ; i ++){if(n % primes[i] == 0){return 0;}}return 1;}
 
//______________________________

ll n, m;
int a[1001][1001];

void solve(){
    while(cin >> n >> m && n && m){
        ll i, j;
        rep(i,n)rep(j,m) a[i][j] = 0;
        ll x;
        cin >> x;
        cin >> ws;
        while(x --){
            string s;
            getline(cin , s);
            istringstream is(s);
            int row;
            is >> row;
            int col;
            is >> col;
            while(is >> col){
                a[row][col] = -1;
            }
        }
        ll sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;
        int dist[n][m];
        rep(i,n)rep(j,m) dist[i][j] = inf;
        dist[sx][sy] = 0;
        queue<ii> q;
        q.push(mkp(sx, sy));
        while(!q.empty()){
            ii top = q.front();
            q.pop();
            int row[] = {0,0,-1,1};
            int col[] = {-1,1,0,0};
            for(i = 0; i < 4 ; i ++){
                ll X, Y;
                X = top.fr + row[i];
                Y = top.sc + col[i];
                if(X >= 0 && X < n && Y >= 0 && Y < m && dist[X][Y] == inf && a[X][Y] == 0){
                    dist[X][Y] = dist[top.fr][top.sc] + 1;
                    q.push(mkp(X, Y));
                }
            }
        }
        cout << dist[dx][dy] << endl;
    }
}

//________________________________

int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(0);
    // freopen("input.in" , "r" , stdin);
    // freopen("output.out" , "w" , stdout);
    solve();
}
 
 
