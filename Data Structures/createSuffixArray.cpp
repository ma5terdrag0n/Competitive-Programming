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


//***********************SUFFIX ARRAY******************************************
int n;
const int max_n = 100010;
int SA[max_n], tempSA[max_n];
int RA[max_n], tempRA[max_n];
int c[max_n];
int r;

void countSort(int k){
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof(c));
	for(i = 0 ; i < n ; i ++){
		c[(i+k) < n ? RA[i+k] : 0]++;
	}
	for(i = sum = 0; i < maxi ; i++){
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for(i = 0 ; i < n ; i ++){
		tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	}
	for(int i = 0 ; i < n ; i++){
		SA[i] = tempSA[i];
	}
}


void SA_create(string s){
	n = s.size();
	cout << n << endl;
	for(int i = 0 ; i < n ; i ++){
		RA[i] = s[i];
		SA[i] = i;
	}
	for(int k = 1 ; k < n ; k <<= 1){
		countSort(k);
		countSort(0);
		tempRA[SA[0]] = r = 0;
		for(int i = 1 ; i < n ; i ++){
			tempRA[SA[i]] = (RA[SA[i-1]] == RA[SA[i]] &&  RA[SA[i]+k] == RA[SA[i-1] + k])?r:++r;
		}
		for(int i = 0 ; i < n ; i ++){
			RA[i] = tempRA[i];
		}
		if(RA[SA[n-1]] == n-1)break;
	}

}


// ****************************************************************************

void solve(){
	string s;
	cin >> s;
	s.push_back('$');
	SA_create(s);
	for(int i = 0 ; i < s.size() ; i ++){
		cout << SA[i] << " ";
	}
	cout << endl;
}

int main(){
    std::ios::sync_with_stdio(0);
    #ifdef ONLINE_JUDGE
    #else
        freopen("input.txt" , "r" , stdin);
       	// freopen("output.txt", "w", stdout);
    #endif
    solve();
}
