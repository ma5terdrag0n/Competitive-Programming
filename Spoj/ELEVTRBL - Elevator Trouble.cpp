#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1000000009

using namespace std;

typedef long long ll;

void solve(){
	ll f,s,g,u,d;
	// floors, start, goal, up, down
	cin>>f>>s>>g>>u>>d;
	queue<ll> q;
	q.push(s);
	ll visited[f+1]={0};
	visited[s]=1;
	while(!q.empty()){
		ll x = q.front();
		q.pop();
		if(x+u <= f && visited[x+u]==0){
			visited[x+u] = visited[x]+1;
			q.push(x+u);
		}
		if(x-d >= 1 && visited[x-d]==0){
			visited[x-d] = visited[x]+1;
			q.push(x-d);
		}
	}
	if(visited[g] == 0){
		printf("%s\n", "use the stairs");
	}else{
		cout<<visited[g]-1<<endl;
	}
}


int main(){
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
