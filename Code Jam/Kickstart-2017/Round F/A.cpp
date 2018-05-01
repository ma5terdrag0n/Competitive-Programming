/*
*  ________________________________________
*      | |     / / 
*      | |    / /   Pritish Thakkar !
*  ____|_|_ _/_/___________________________
*      | |  / /   
*      | | / /      Dream Big ! Work Hard !  
*  ____|_|/_/______________________________
*/
 
#include<bits/stdc++.h>
#define         pb                      push_back
#define         mkp                     make_pair
#define         inf                     1000000007
#define         REV(i, x, y)            for(int i = x ; i >= y ; i-- )
#define         FOR(i, x, y)            for(int i = x ; i <= y ; i++ )
#define         rep(i, n)               for(int i = 0 ; i < n ; i++  )
#define         fr                      first
#define         sc                      second
#define         clr(a)                  memset(a,0LL,sizeof a);
#define         pi                      3.141592653589793
#define         gc                      getchar
#define         all(v)                  v.begin(), v.end()
#define         filein                  freopen("input.in" , "r" , stdin)
#define         fileout                 freopen("output.out" , "w" , stdout)
#define         test                    ll t; cin >> t; while(t--)
#define         ntest                   ll t; t = 1;    while(t--)
#define         sz(x)                   x.size()
#define         pass                    {}
 
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
 
ll modpow(ll base, ll expo, ll mod){
base  = base % mod;
ll ret = 1LL;
while(expo > 0){
    if(expo & 1LL){ret =( ret * base) % mod;}
    base = (base * base )% mod;expo >>= 1LL;
}
return ret;
}
 
bool p[10000001];
vi primes;
void sieve(ll n){
    memset(p,1,sizeof p);
    p[0] = p[1] = 0;
    for(int i = 2 ; i <= sqrt(n) ; i++){
        if(p[i]){
            for(int j = i * i ; j < n ; j+=i){p[j] = 0;}
        }
    }
    for(int i = 2 ; i <= n ; i ++){if(p[i]){primes.pb(i);}}
}
 
bool isPrime(ll n){
    if(n < 1000001){
        return p[n];
    }
    ll ans = 0;
    for(int i= 0 ; i < primes.size() && primes[i] * primes[i] <= n  ; i ++){
        if(n % primes[i] == 0){return 0;}
    }return 1;
}
 
ll phi(ll n){
    ll ans = n;
    vi v;
    v.clear();
    for(int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i ++){
        if(n % primes[i] == 0){
            v.push_back(primes[i]);
            while(n % primes[i] == 0){
                n /= primes[i];
            }
        }
    }
    if(n != 1){
        v.push_back(n);}
    for(int i = 0 ; i < v.size() ; i ++){
        ans = ans - ans / v[i];
    }
    return ans;
}
 
ull nCr(ll n, ll r){
    if(r > n / 2){
        r = n - r;
    }
    ull ret = 1;
    for(ll i = 1 ; i<= r ; i ++){
        ret *=  (n - r + i);
        ret /= i;
    }
    return ret;
}
 
template<class T >
string toString(T n){
    string v = "";
    while(n){
        v.pb(n % 10 + '0');
        n /= 10;
    }
    reverse(all(v));
    return v;
}
 
ll toInt(string s){
    ll ret = 0;
    for(int i = 0 ; i < s.size() ; i ++){
        ret = ret * 10 + (s[i] - '0');
    }
    return ret;
}
 
ll binary_search(ll *a, int lo, int hi, ll key){
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
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
 
 
 
//__________________________________

ll n;
ll a[100000];

ll part(ll, ll);

bool fun(ll lo, ll hi){
    if(lo < hi){
        ll mid = part(lo, hi);
        // cout << mid << " " << lo << " " << hi << endl;
        if(mid != hi and mid != lo){
            cerr << "This\n";
            return 0;
        }
        bool x = fun(lo, mid - 1);
        bool y = fun(mid + 1, hi);
        return (x && y);
    }
    return 1;
}

ll part(ll lo, ll hi){
    ll p = (hi + lo) / 2;
    vector<ll> left, right;
    for(int i = lo; i <= hi ; i ++){
        if(a[i] < a[p]){
            left.pb(a[i]);
        }
        else if(a[i] > a[p])
            right.pb(a[i]);
    }
    ll ret = lo;
    for(int i = 0 ; i < left.size() ; i ++){
        a[lo] = left[i];
        lo++;
    }
    ret = lo;
    a[lo++] = a[p];
    for(int i = 0 ; i < right.size() ; i ++){
        a[lo] = right[i];
        lo++;
    }
    return ret;
}

void solve(){
    ll t;
    cin >> t;
    ll counter = 0;
    while(t--){
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        cout << "Case #" << ++counter << ": ";
        if(fun(0, n - 1)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        
    }
}

//________________________________
 
void donuts(){
    filein; 
    fileout;
}
 
int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(0);
    donuts();
    solve();
}
