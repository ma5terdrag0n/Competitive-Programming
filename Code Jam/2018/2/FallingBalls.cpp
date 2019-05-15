#include <bits/stdc++.h>

#include <unordered_map> 
#include <cstdio>
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

//------------------------------------------------------------------------

void solve(ll testcase){
  ll n;
  cin >> n;
  ll a[n];
  rep(n){
    cin >> a[i];
  }
  cout << "Case #" << testcase << ": ";

  if(a[0] == 0 or a[n-1] == 0){
    cout << "IMPOSSIBLE\n";
    return;
  }

  bool complete[n] = {0};

  vector<char> grid[200];
  for(int i = 0 ; i < 200; i++){
    grid[i].resize(200, '.');
  }
  ll where = 1;
  ll target = 0;
  a[0]--;
  a[n-1]--;
  for(int i = 1 ; i < n-1 ; i ++){
    while(target < n and a[target] == 0) target++;
    // cout << i << " " << target << endl;
    if(target == i){
      a[target]--;
    }
    else if(target < i){
      ll row = 0,col = i;
      while(col > target){
        grid[row++][col--] = '/';
      }
      where = max(row+1, where);
      a[target]--;
    }else{
      ll row = 0,col = i;
      while(col < target){
        grid[row++][col++] = '\\';
      }
      where = max(row+1, where);
      a[target]--;
    }
  }

  cout << where << endl;
  rep(where){
    repc(j, n){
      cout << grid[i][j];
    }
    cout << endl;
  }
}

int main()
{
  std::ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef ONLINE_JUDGE
#else
 // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  ll t = 1;
  cin >> t;
  ll cas = 0;
  while (t--)
  {
    solve(++cas);
  }
}
