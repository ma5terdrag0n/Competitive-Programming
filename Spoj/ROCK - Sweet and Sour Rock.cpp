#include<bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long ll;

ll best[222][222],n;
ll dp[222][222];
string s;

ll fun(ll s,ll e){
	if(s > e){
		return 0;
	}
	if(dp[s][e] == -1LL){
		dp[s][e]=0;
		for(int i=s;i<=e;i++){
			ll aux = best[s][i]+fun(i+1,e);
			if(dp[s][e] < aux){
				dp[s][e] = aux;
			}
		}
	}
	return dp[s][e];
}	

void solve(){
	ll t;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof dp);
		memset(best,0,sizeof best);
		cin>>n>>s;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				for(int k=j,diff=0;k>=i;k--){
					if(s[k] =='1'){
						diff++;
					}else{
						diff--;
					}
					if(diff > 0){
						best[i][j] = j-k+1;
					}
				}
				
			}
		}
		cout<<fun(0,n-1)<<endl;
	}
}

int main(){
	ios::sync_with_stdio(0);
	solve();
}
