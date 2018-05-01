/*
*  Author : __daemon 
*/
#include<bits/stdc++.h>
#define pb push_back
#define mkp make_pair
#define inf 1000000009
#define rep(i,n) for(int i=0;i<n;i++)
#define fr first
#define sc second
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
 
void clr(ll *a,ll val){
  memset(a,val,sizeof(a));
}

ll n=33333,m = 555555;
ll universe[333333],maxi[333333];

ll getparent(ll index){
	return (universe[index] == index) ? index : universe[index] = getparent(universe[index]);
}

void unionize(ll index1,ll index2){
	ll parent1 = getparent(index1);
	ll parent2 = getparent(index2);
	universe[parent1] = parent2;
}

void solve(){
	ll t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			universe[i]=i;
		}		
		for(int i=0;i<m;i++){
			ll u,v;
			cin>>u>>v;
			if(getparent(u) != getparent(v)){
				unionize(u,v);
			}
		}
		memset(maxi,0,sizeof maxi);
		for(int i=1;i<=n;i++){
			maxi[getparent(i)]++;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans = max(maxi[i],ans);
		}
		cout<<ans<<endl;
	}
}



int main(){
	solve();
} 





