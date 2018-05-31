/**
 *
 *  Tony Stark
 *
 **/
#include<bits/stdc++.h>
#include<cstdio>
#define pb push_back
#define mp make_pair
#define inf 1000000007
#define fr first
#define sc second
#define eps 1e-9
#define clr(a) memset(a, 0, sizeof(a))1
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
 
// UTILITY FUNCTIONS
bool isUpper(char c) {return (c >= 'A' && c <= 'Z');}
bool isLower(char c) {return (c >= 'a' && c <= 'z');}
bool iplpha(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z');}
bool isnum(char c){return (c >= '0' and c <= '9');}
bool isalnum(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z')||(c >= '0' && c <= '9');}
char toUpper(char c){return isUpper(c)?c:c-'a'+'A';}
char toLower(char c){return isLower(c)?c:c+'a'-'A';}
bool isvowel(char c){c = toLower(c); return (c == 'a' or c == 'e' or c == 'i' or c == 'i' or c == 'o' or c == 'u' || c == 'y');}
template<typename t> t gcd(t a, t b){a = abs(a), b = abs(b);return ((b == 0) ? a : gcd(b, a%b));}
template<typename t> t lcm(t a, t b){return (a * (b / gcd(a, b)));}
template <typename T> T modpow(T base, T exp, T modulus) {base %= modulus;T result = 1;while (exp > 0) {if (exp & 1) result = (result * base) % modulus;base = (base * base) % modulus;exp >>= 1;}return result;}
string toLowerCase(string s){rep(s.size()){if(!isLower(s[i])){s[i] = toLower(s[i]);}}return s;}
string toUpperCase(string s){rep(s.size()){s[i] = toUpper(s[i]);}return s;}
template<typename T> void cumulative(T *a, T *b, T n){rep(n){i ? b[i] = b[i-1] + a[i] : b[i] = a[i];}}
bool ispal(string s){ll lo, hi;lo = 0;hi = s.length()-1;while(lo <= hi){if(s[lo] != s[hi]){return 0;}lo++;--hi;}return 1;}
template<class T >string toString(T n){string v = "";while(n){v.pb(n % 10 + '0');n /= 10;}reverse(all(v));return v;}

ll binary_search(vi a, ll n, ll key){
    ll lo = 0;
    ll hi = n - 1;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(a[mid] == key){
            return mid;
        }
        else if(a[mid] < key){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return -1;
}

//------------------------------------------------------------------------

ll a[1000001];

void sol(){
	ll  N, K, x1, y1, C, D, E1, E2, F;
	cin >>  N >> K >> x1 >> y1 >> C >> D >> E1 >>  E2 >> F;

	a[0] = (x1 + y1) % F;
	for(int i = 1 ; i < N ; i++){
		ll tmp1, tmp2;
		tmp1 = x1, tmp2 = y1;
		x1 = (C * tmp1 + D * tmp2 + E1) % F;
		y1 = (D * tmp1 + C * tmp2 + E2) % F;
		a[i] = (x1 + y1) % F;
	}

	ll ans = 0LL;

	ll mod = inf;

	ll n = N;

	ll k = K;

	ll powers[N + 1];
	for(ll i = 1 ; i <= n ; i ++){
		if(i==1){
			powers[i] = k;
			continue;
		}
		powers[i] = (i * (modpow(i, k, mod) - 1 + mod) % mod * modpow(i-1, mod-2, mod)) % mod;
	}

	for(int i = 2 ; i <= N ; i++){
		powers[i] = (powers[i] + powers[i-1]) % mod;
	}

	for(int i = 0 ; i < n ; i ++){
		ans = ( ans + (n - i) * ((a[i]) * powers[i+1] % mod) % mod ) % mod;
	}
	cout << ans << endl;

}



void solve(){
	ll t;
	cin >> t;
	for(int cas = 1 ; cas <= t ; cas ++){
		cout << "Case #" << cas << ": ";
		sol();
	}
}

int main(){
    std::ios::sync_with_stdio(0);
    #ifdef ONLINE_JUDGE
    #else
        freopen("input.txt" , "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
}


















