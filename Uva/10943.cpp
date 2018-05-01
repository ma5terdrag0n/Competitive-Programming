#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define inf 1000000007
#define fr first
#define sc second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
bool isLower(char c){
	return (c <= 'z' and c >= 'a');
}

ll w[111][111];
const ll mod = 1e6;


int fun(ll k, ll n){
	if(w[k][n] != -1){
		return w[k][n];
	}
	if(k == 1){
		return w[k][n] = 1;
	}
	int ans = 0;
	for(int i = 0 ; i <= n ; i ++){
		ans = (ans % mod  + fun(k-1, i) % mod) % mod;
	}
	return (w[k][n] = ans);
}

void solve(){
	ll n, k;
	ll dp[1000][1000];
	while(cin >> n >> k and (n && k)){
		memset(w,-1,sizeof(w));
		cout << fun(k , n) << endl;
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
