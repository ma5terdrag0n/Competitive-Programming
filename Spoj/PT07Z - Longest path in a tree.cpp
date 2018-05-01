#include<bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long ll;

ll n;
map<ll,std::vector<ll> > m;
ll ans;
ll color[1234567];


ll dfs(ll index){
	color[index] = 1;
	vector<ll> ve;
	for(int i = 0 ; i < m[index].size() ; i++){
		ll v;
		v = m[index][i];
		if(color[v] == 0){
			ll foo = dfs(v);
			ve.pb(foo);
		}
	}
	if(ve.size() == 0){
		ans = max(ans,1LL);
		return 1;
	}
	if(ve.size()==1){
		ans = max(ans,ve[0]);
		return ve[0]+1;
	}
	ll max1,max2;
	max1=max2=0;
	sort(ve.begin(), ve.end());
	max1 = ve[ve.size()-1];
	max2 = ve[ve.size()-2];
	ans = max(ans,max1+max2);
	return max1+1;
}


int main(){
	ans=0;
	memset(color,0,sizeof color);
	cin>>n;
	for(int i = 0 ; i < n-1; i++){
		ll u,v;
		cin>>u>>v;
		m[v].pb(u);
		m[u].pb(v);
	}
	ll temp = dfs(1);
	cout<<ans<<endl;

}
