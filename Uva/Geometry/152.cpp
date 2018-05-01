#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define inf 1000000007
#define fr first
#define sc second
#define eps 1e-9
#define sni(x) scanf("%d",&x)
#define snl(x) scanf("%lld", &x)
#define snc(x) scanf("%c", &c);
#define rep(i, n) for(int i = 0 ; i < n ;i ++)
#define FOR(i, x, y) for(int i = x ; i < y ; i ++)
#define DEC(i, x, y) for(int i = x ; i >= y ; i --)
#define all(v) v.begin(), v.end()
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

bool isLower(char c){
    return (c <= 'z' and c >= 'a');
}

char toLower(char c){
    return c - 'A' + 'a';
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



struct point3d{
    int x, y, z;
};

ll dist(point3d a, point3d b){
    ll dx, dy, dz;
    dx = b.x - a.x;
    dy = b.y - a.y;
    dz = b.z - a.z;
    return dx * dx + dy * dy + dz * dz;
}

void solve(){
    ll X, Y, Z;
    struct point3d a[5001]; 
    ll counter = 0;
    while(cin >> X >> Y >> Z){
        if(X == 0 and Y == 0 and Z == 0)break;
        a[counter].x = X;
        a[counter].y = Y;
        a[counter++].z = Z;
    }
    ll ans[10] = {0};
    rep(i, counter){
        ll mini = 0xfffffff;
        rep(j, counter){
            if(i != j){
                mini = min(mini, (dist(a[i], a[j])));
            }
        }
        ll d = sqrt(mini);
        if(d <= 9){
            ans[d]++;
        }
    }
    for(int i = 0 ;i < 10; i ++){
        cout << setw(4);
        cout << ans[i];
    }
    cout << endl;
}

int main(){
    std::ios::sync_with_stdio(0);
    solve();
}

