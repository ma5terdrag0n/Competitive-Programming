/* *
 *
 *  Tony Stark
 *
 **/
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
template<typename t> t gcd(t a, t b){a = abs(a), b = abs(b);return ((b == 0) ? a : gcd(b, a%b));}
template<typename t> t lcm(t a, t b){return (a * (b / gcd(a, b)));}
template <typename T> T modpow(T base, T exp, T modulus) {base %= modulus;T result = 1;while (exp > 0) {if (exp & 1) result = (result * base) % modulus;base = (base * base) % modulus;exp >>= 1;}return result;}
string toLowerCase(string s){rep(s.size()){if(!isLower(s[i])){s[i] = toLower(s[i]);}}return s;}
string toUpperCase(string s){rep(s.size()){s[i] = toUpper(s[i]);}return s;}
template<typename T> void cumulative(T *a, T *b, T n){rep(n){i ? b[i] = b[i-1] + a[i] : b[i] = a[i];}}
bool ispal(string s){ll lo, hi;lo = 0;hi = s.length()-1;while(lo <= hi){if(s[lo] != s[hi]){return 0;}lo++;--hi;}return 1;}
template<class T >string toString(T n){string v = "";while(n){v.pb(n % 10 + '0');n /= 10;}reverse(all(v));return v;}
template<class T>
void fs(T &number){bool negative = false;register int c;number = 0;c = getchar();if (c=='-'){negative = true;c = getchar();}for (; (c>47 && c<58); c=getchar())number = number *10 + c - 48;if (negative)number *= -1;}
double areaOfTriangle(double ax, double ay, double bx, double by, double cx, double cy){
    double ans = 1.00 * fabs(ax * (by - cy) + bx * (cy - ay) + cx * (ay - by))/2.00;
    return ans;
}

//----------------------------


void solve(){
	 ll t;
	 cin >> t;
	 while(t--){
	 	ll n;
	 	cin >> n;
	 	ll a[n];
	 	rep(n){
	 		cin >> a[i];
	 	}
	 	ll idx = -1;
	 	for(int i = n-1; i > 0 ; i --){
	 		if(a[i] <= a[i-1])continue;
	 		else{
	 			idx = i-1;
	 			break;
	 		}
	 	}
	 	if(idx!=-1){
	 		for(int i = 0 ; i < idx ; i ++){
	 			cout << a[i];
	 		}
	 		ll foo = a[idx];
	 		ll maxi = a[idx+1];
	 		ll index=idx+1;
	 		for(int i = idx ; i < n ; i ++ ){
	 			if(a[i] > a[idx] && a[i] < maxi){
	 				maxi = a[i];
	 				index = i;
	 			}
	 		}
	 		swap(a[idx], a[index]);
	 		sort(a + idx+1, a + n);
	 		for(int i = idx;i < n;i ++){
	 			cout << a[i];
	 		}
	 		cout << endl;
	 	}else{
	 		cout << idx << endl;
	 	}
	 }
}

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    int start = clock();

    // freopen("input.txt" , "r" , stdin);
    solve();
    // freopen("output.txt", "w", stdout);

}
