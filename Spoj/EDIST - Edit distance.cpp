#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		ll l1,l2;
		l1 = a.size()+1;
		l2 = b.size()+1;
		ll dp[l1][l2];
		for(int i=0;i<l1;i++){
			dp[i][0] = i;
		}
		for(int j=0;j<l2;j++){
			dp[0][j] = j;
		}
		for(int i=1;i<l1;i++){
			for(int j=1;j<l2;j++){
				if(a[i-1] == b[j-1]){
					dp[i][j] = dp[i-1][j-1];
				}else{
					dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
				}
			}
		}
//		for(int i=0;i<l1;i++)
//		{
//			for(int j=0;j<l2;j++){
//				cout<<dp[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		cout<<dp[l1-1][l2-1]<<endl;
		
	}
}
