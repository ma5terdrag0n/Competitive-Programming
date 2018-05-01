#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define inf 1000000007
#define fr first
#define sc second
#define eps 1e-15
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
bool isLower(char c){
	return (c <= 'z' and c >= 'a');
}
 

bool comp(string a, string b){
	return (a > b);
}

ll bs(vector<ll> &v, ll lo, ll hi, ll fin){
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(v[mid] == fin){
            return mid;
        }
        else if(v[mid] < fin){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return -1;
}

void solve(){
    int n, u;
    scanf("%d%d",&n,&u);
    int a[n + 1] = {0};
    for(int i = 0 ; i < u ; i ++){
        int x, y, wt;
        scanf("%d%d%d", &x,&y,&wt);
        a[x] += wt;
        a[y + 1] -= wt;
    }
    for(int i = 1 ; i < n ;i ++){
        a[i] += a[i-1];
    }
    int q;
    scanf("%d", &q);
    for(int i = 0 ; i < q ; i ++){
        int pos;
        scanf("%d",&pos);
        printf("%d\n",a[pos]);
    }

}
 
int main(){
	ll t = 1;
	cin >> t;
	while(t--)
	solve();
} 
