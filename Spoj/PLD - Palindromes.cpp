#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define inf 1000000007
#define fr first
#define sc second
#define eps 1e-15
#define sni(x) scanf("%d",&x)
#define snl(x) scanf("%lld", &x)
#define snc(x) scanf("%c", &c);
#define rep(i, n) for(int i = 0 ; i < n ;i ++)
#define FOR(i, x, y) for(int i = x ; i < y ; i ++)
#define DEC(i, x, y) for(int i = x ; i >= y ; i --)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

bool isLower(char c){
    return (c <= 'z' and c >= 'a');
}

template<typename c>
int binary_search(c *a, int lo, int hi, c key){
    while(lo <= hi){
        int mid = (lo + hi) / 2;
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

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

string toLowerCase(string s){
    rep(i, s.size()){
        if(!isLower(s[i])){
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}

//--------------------------------------------------------------------

int ispal(string s, ll start, ll end){
    while(start <= end){
        if(s[start] == s[end]){
            start ++;
            end--;
        }else{
            return 0;
        }
    }
    return 1;
}

void solve(){
       ll n;
       cin >> n;
       string s;
       cin >> s;
       // cout << n << " "<< s << endl;
       ll ans = 0;
       for(int i = 0 ; i < s.size() ; i ++){
            if(i + n > s.size()){
                break;
            }
            ans += ispal(s, i, i + n - 1);
       }
       cout << ans << endl;
}


int main(){
    std::ios::sync_with_stdio(0);
    // int start = clock();
    freopen("input.in" , "r" , stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    // cout << n;
    // int stop = clock();
    // cout << (stop - start) / 1000.0000<< endl;
}
