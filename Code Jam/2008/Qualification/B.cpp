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
#define         rep(i,n)                for(int i=0;i<n;i++)
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
    ll ret = 1LL;while(expo > 0){
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

int formatT(string s){
    int hh, mm;
    hh = mm = 0;
    hh = (s[0] - '0')*10 + (s[1] - '0');
    mm = (s[3] - '0')*10 + (s[4] - '0');
   
    return (hh*60 + mm);
}

int ta;

ll fun(vi from, vi to){
    sort(all(from));
    sort(all(to));
    ll ret, j;
    ret = j = 0;
    for(int i= 0 ; i < from.size() ; i ++){
        if(j < to.size() and ta + to[j] <= from[i]){
            j++;
        }else{
            ret++;
        }
    }
    return ret;
}

 
void solve(){
    ll t;
    cin >> t;
    for(int cas = 0 ; cas < t ; cas ++){
        cin >> ta;
        ll n, m;
        cin >> n >> m;
        vi af, at, bf, bt;
        for(int i = 0 ; i < n; i ++){
            string a, b;
            cin >> a >> b;
            int fa = formatT(a);
            int fb = formatT(b);
            af.pb(fa);  // from a 
            bt.pb(fb);  // to b
        }

        for(int i = 0 ; i < m; i ++){
            string a, b;
            cin >> a >> b;
            int fa = formatT(a);
            int fb = formatT(b);
            bf.pb(fa);  // from b
            at.pb(fb);  // to a
        }
        ll ansa, ansb;
        ansa = fun(af, at);
        ansb = fun(bf, bt);
        cout << "Case #" << cas + 1 << ": " << ansa << " " << ansb << endl;  

    }
}
 
//________________________________

int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(0);
    filein; 
    fileout;
    solve();
}
 
