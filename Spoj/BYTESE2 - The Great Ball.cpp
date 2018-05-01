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
 
int fun(pair<int, int> p1, pair<int, int > p2){
    return (p1.sc >= p2.fr);
} 


void solve(){
    int t;
    sni(t);
    while(t--){
        int n;
        sni(n);
        pair<int, int> p[n];
        rep(i, n){
            int x, y;
            sni(x);
            sni(y);
            p[i] = mp(x, y);
        }
        sort(p , p + n);
        int ans = 0;
        rep(i, n){
            int Tans = 0;
            rep(j, n){
                Tans += (p[j].fr <= p[i].fr and p[j].sc >= p[i].fr);
            }
            ans = max(ans, Tans);

        }
        printf("%d\n", ans);
    }
}

int main(){
    // int start = clock();
    freopen("input.in" , "r" , stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    // cout << n;
    // int stop = clock();
    // cout << (stop - start) / 1000.0000<< endl;
}
