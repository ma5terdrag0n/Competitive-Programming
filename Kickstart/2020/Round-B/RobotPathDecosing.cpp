#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include<iomanip>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define sz(x) x.size()
#define rep(n) for (ll i = 0; i < n; i++)
#define repc(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define DEC(i, x, y) for (int i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a + n

using namespace std;

// Some typedef's
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

// UTILITY FUNCTIONS

// String
char toUpper(const char &c) { return isupper(c) ? c : c - 'a' + 'A'; }
char toLower(const char &c) { return islower(c) ? c : c + 'a' - 'A'; }
bool isvowel(char c){  c = toLower(c);return (c == 'a' or c == 'e' or c == 'i' or c == 'i' or c == 'o' or c == 'u' || c == 'y');}
void toLowerCase(string &s){rep(s.size()){  if (!islower(s[i]))  {    s[i] = tolower(s[i]);  }}}
void toUpperCase(string &s){rep(s.size()) { s[i] = toupper(s[i]); }}
bool ispal(string s){  ll lo, hi;  lo = 0;  hi = s.length() - 1;  while (lo <= hi)  {    if (s[lo] != s[hi])    {      return 0;    }    lo++;    --hi;  }  return 1;}
template <class T>string toString(T n){  string v = "";  while (n)  {    v.pb(n % 10 + '0');    n /= 10;  }  reverse(all(v));  return v;}

// Maths
template <typename t>t gcd(t a, t b){  a = abs(a), b = abs(b);  return ((b == 0) ? a : gcd(b, a % b));}
template <typename t>t lcm(t a, t b) { return (a * (b / gcd(a, b))); }
template <typename T>T modpow(T base, T exp, T modulus){  base %= modulus;  T result = 1;  while (exp > 0)  {    if (exp & 1)      result = (result * base) % modulus;    base = (base * base) % modulus;    exp >>= 1;  }  return result;}
template <typename T>void cumulative(T *a, T *b, T n){  rep(n) { i ? b[i] = b[i - 1] + a[i] : b[i] = a[i]; }}

// Some constants
const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

//--------------




ii fun(int factor, string s) {
	ll mod = 1000000000;
	ii ret = mp(0,0); 
	string tmp = "";
	ll n, w;
	n = w = 0;
	rep(sz(s)) {
		n = (n + (s[i] == 'S')) % mod;
		n = (n - (s[i] == 'N') + mod) % mod;
		w = (w + (s[i] == 'E')) % mod;
		w = (w - (s[i] == 'W') + mod) % mod;
		if(s[i] >= '0' and s[i] <= '9') {
			int fa = s[i] - '0';
			i+=2;
			int start = i;
			tmp = "";
			int counti = 1;
			int len = 0;
			while(i < sz(s) and counti != 0){
				if(s[i] == '(') counti++;
				if(s[i] == ')') counti--;
				len ++;
				i++;
			}
			tmp = s.substr(start, len-1);
			i--;
			ii def = fun(fa, tmp);
			n = (n + def.fr) % mod;
			w = (w + def.sc) % mod;
		}
	}
	n = n * factor % mod;
	w = w * factor % mod;
	return mp(n, w);
}

void sol(ll cas) {
	string s;
	cin >> s;
	ii x = fun(1, s);
	cout << "Case #" << cas << ": " << x.sc + 1 << " " << x.fr + 1  << endl;
}

void solve() {
	ll t;
	cin >> t;
	ll cas = 0;
	while(t--){
		sol(++cas);
	}
}

int main() {
	solve();
	return 0;
}
