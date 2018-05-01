#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1000000009

using namespace std;

typedef long long ll;

void solve(){
	ll n;
	while(cin>>n){
		ll i;
		ll a[n];
		rep(i,n)
			cin>>a[i];
		ll j;
		ll smoke[n][n],result[n][n];
		rep(i,n){
			rep(j,n){
				smoke[i][j] = result[i][j] = 0;
			}
		}
		rep(i,n){
			smoke[i][i] = 0;
			result[i][i] = a[i];
		}
		for(int i=0;i<n;i++){
			for(ll j=i+1;j<n;j++){
				result[i][j] = (result[i][j-1]+a[j])%100;			
			}
		}
		for(int count=2;count<=n;count++){
			for(int i=0;i<n-count+1;i++){
				j = i+count-1;
				smoke[i][j] = inf;
				if(count==2){
					smoke[i][j] = a[i]*a[j];
					continue;
				}
				for(int k = i ; k < j ; k++){
					ll q = smoke[i][k] + smoke[k+1][j] + result[i][k]*result[k+1][j];
					if(q < smoke[i][j]){
						smoke[i][j] = q;
					}
				}
			}
		}
		// rep(i,n){
		// 	rep(j,n){
		// 		cout<<smoke[i][j]<<","<<result[i][j]<<"\t\t\t";
		// 	}
		// 	cout<<endl;
		// }
		cout<<smoke[0][n-1]<<endl;
	}	
}


int main(){
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
