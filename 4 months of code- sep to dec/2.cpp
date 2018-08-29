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

// bool p[1000001];
// vi primes;

// void sieve(){
//     p[0] = p[1] = 0;
//     for(int i=2 ;i <= 1000000 ; i++){
//         p[i] = 1;
//     }
//     for(int i = 2 ; i*i < 1000001 ; i++){
//         if(p[i] == 1){
//             for(int j = i * i ; j < 1000001 ; j += i){
//                 p[j] = 0;
//             }
//         }
//     }
//     for(int i = 0 ; i < 1000001 ; i ++){
//         if(p[i]){
//             primes.pb(i);
//         }
//     }
// }

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

void solve(){
	
}

int main(){
	// freopen("input.txt", "r", stdin);

	ll n;
	cin >> n;
	vi v;
	rep(n){
		ll x;
		cin >> x;
		v.pb(x);
	}
	ll ans = 1;
	ll tmp = 0;
	ll last = 0;
	rep(n){
		ll pos = upper_bound(all(v), 2*v[i] - 1) - v.begin();
		if(pos == v.size()){
			ans = max(ans, n - last);
			break;
		}
		while(pos >= 0 and v[pos] > 2*v[i])pos--;
		// cout << i << " " << pos << endl;
		if(pos+1 < n and v[pos]*2 < v[pos+1]){
			ans = max(ans, pos-last+1);
			// cout << ans << endl;
			last = pos + 1;
			i = pos;
			continue;
		}
		i = pos;
		tmp = pos - last + 1;
		// cout << tmp << endl;
		ans = max(ans, tmp);
	}

	cout << ans << endl;

}
