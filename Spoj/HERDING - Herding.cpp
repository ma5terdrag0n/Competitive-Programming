#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1000000009
#define ll long long 
using namespace std;

typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

char c[1111][1111],color[1234567];	
map<ll,vi> adj;
ll n,m;

void dfs(ll index){
	color[index] = 1;
	for(int i=0;i<adj[index].size();i++){
		ll ver = adj[index][i];
		if(color[ver] == 0){
			dfs(ver);
		}
	}
	return;
}
void solve(){
	memset(color,0,sizeof color);
	cin>>n>>m;
	ll i,j;
	ll done=1;
	rep(i,n){
		rep(j,m){
			cin>>c[i][j];
			if(c[i][j] == 'S'){
				if(i+1 < n){
					ll one,two;
					one = done; 
					two = done+m;
					adj[one].pb(two);
					adj[two].pb(one);
				}
			}if(c[i][j] == 'N'){
				if(i-1 >= 0){
					ll one,two;
					one = done; 
					two = done-m;
					adj[one].pb(two);
					adj[two].pb(one);
				}
			}if(c[i][j] == 'E'){
				if(j+1 < m){
					ll one,two;
					one = done; 
					two = done+1;
					adj[one].pb(two);
					adj[two].pb(one);
				}
			}if(c[i][j] == 'W'){
				if(j-1 >= 0){
					ll one,two;
					one = done; 
					two = (done)-1;
					adj[one].pb(two);
					adj[two].pb(one);
				}
			}
			done++;
		}
	}
	ll ans=0;
	for(int i=1;i<=n*m;i++){
		if(color[i] == 0){
			ans++;
			dfs(i);
		}
	}
	
	cout<<ans;
}


int main(){
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
