/*
*  Author : pritish.thakkar 
*/

#include<bits/stdc++.h>
#define         pb                      push_back
#define         mkp                     make_pair
#define         inf                     1000000007
#define         rep(i,n)                for(int i=0;i<n;i++)
#define         fr                      first
#define         sc                      second
#define         clr(a)                  memset(a,0LL,sizeof a);
#define         pi                      3.141592653589793
#define         gc                      getchar
#define         all(v)                  v.begin(), v.end()
#define         filein                  freopen("input.in" , "r" , stdin)
#define         fileout                 freopen("output.in" , "w" , stdout)
using           namespace               std;

typedef         unsigned long long      ull;
typedef         long long               ll;
typedef         vector<ll>              vi;
typedef         pair<ll,ll>             ii;
typedef         vector<ii>              vii;
typedef         set<ll>::iterator       sit;
typedef         map<ll,ll>::iterator    mit;
typedef         vector<int>::iterator   vit;

template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}

//_____________________________

bool isUpper(char c) {return (c >= 'A' && c <= 'Z');}
bool isLower(char c) {return (c >= 'a' && c <= 'z');}
bool iplpha(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z');}
bool iplnum(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z')||(c >= '0' && c <= '9');}
char toUpper(char c){return isUpper(c)?c:c-'a'+'A';}
char toLower(char c){return isLower(c)?c:c+'a'-'A';}
template<typename t> t gcd(t a, t b){return ((b == 0) ? a : gcd(b, a%b));} 
template<typename t> t lcm(t a, t b){return (a * (b / gcd(a, b)));}

ll modpow(ll base, ll expo, ll mod){base  = base % mod;ll ret = 1LL;while(expo > 0){if(expo & 1LL){ret =( ret * base) % mod;}base = (base * base )% mod;expo >>= 1LL;}return ret;}
bool p[10000001];
vi primes;
void sieve(ll n){memset(p,1,sizeof p);p[0] = p[1] = 0;for(int i = 2 ; i <= sqrt(n) ; i++){if(p[i]){for(int j = i * i ; j < n ; j+=i){p[j] = 0;}}}for(int i = 2 ; i <= n ; i ++){if(p[i]){primes.pb(i);}}}
bool isPrime(ll n){if(n < 1000001){return p[n];}ll ans = 0;for(int i= 0 ; i < primes.size() && primes[i] * primes[i] <= n  ; i ++){if(n % primes[i] == 0){return 0;}}return 1;}
ll phi(ll n){ll ans = n;vi v;v.clear();for(int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i ++){if(n % primes[i] == 0){v.push_back(primes[i]);while(n % primes[i] == 0){n /= primes[i];}}}if(n != 1){v.push_back(n);}for(int i = 0 ; i < v.size() ; i ++){ans = ans - ans / v[i];}return ans;}

void solve(){
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll i, j;
        ll a[n][m];
        ll ans[n][m];
        queue<ii> q;
        rep(i,n) rep(j,m){
            char c;
            cin >> c;
            a[i][j] = (c == '1');
            if(a[i][j] == 1){
                q.push(ii(i, j));
                ans[i][j] = 0;
            }else{
                ans[i][j] = inf;
            }
        }
        while(!q.empty()){
            ll x, y;
            x = q.front().fr;
            y = q.front().sc;
            q.pop();
            ll row[] = {0,0,1,-1};
            ll col[] = {-1,1,0,0};
            for(int i = 0 ; i < 4 ; i ++){
                ll X, Y;
                X = x + row[i];
                Y = y + col[i];
                if(X < n && X >= 0 && Y >= 0 && Y < m && ans[X][Y] > ans[x][y] + 1){
                    ans[X][Y] = ans[x][y] + 1;
                    q.push(ii(X, Y));
                }
            }
        }
        rep(i,n){
            rep(j, m){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }

    }
}

//________________________________

int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(0);
    // filein; fileout;
    solve();
}
 
 
