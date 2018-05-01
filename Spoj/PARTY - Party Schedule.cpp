/*
*   0-1 Knapsack Version
*   Author : Pritish Thakkar
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

void solve(){
	ll c,n;
	while(cin>>c>>n, c && n){
		ll cost[n],fun[c];
		ll i;
		rep(i,n){
			cin>>cost[i]>>fun[i];
		}
		ll dp[n+1][c+1];
		for(int i=0;i<=n;i++){
			for(int j=0;j<=c;j++){
				if(i==0 || j==0){
					dp[i][j] = 0LL;
				}
				else if(j >= cost[i-1]){
					dp[i][j] = max(dp[i-1][j], fun[i-1]+dp[i-1][j-cost[i-1]]);
				}else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		ll money=0;
		for(int i=0;i<=c;i++){
			if(dp[n][i] == dp[n][c]){
				money = i;
				break;
			}
		}
		cout<<money<<" "<<dp[n][c]<<endl;
	}	
}


int main(){
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
