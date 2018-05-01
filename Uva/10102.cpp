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


void solve(){
	char c[1000][1000];
	int dist[1000][1000];
	ll n;
	while(cin >> n){
		for(int i = 0 ; i < n ;i ++){
			for(int j = 0 ; j < n ; j ++){
				cin >> c[i][j];
				dist[i][j] = -1;
			}
		}
		ll x = 0;
		int ans = 0;
		for(int i = 0 ; i < n ; i ++){
			for(int j = 0 ; j < n ; j ++){
				if(c[i][j] == '1'){
					int row[] = {0,0,-1,1};
					int col[] = {-1,1, 0,0};
					queue<pair<int, int> > q;
					q.push(mp(i, j));
					dist[i][j] = 0;
					int mini = (1 << 30);
					while(!q.empty()){
						int RR = q.front().fr;
						int CC = q.front().sc;
						q.pop();
						for(int  k = 0 ;  k < 4 ; k ++){
							int R = RR + row[k];
							int C = CC + col[k];
							if(R >= 0 and C >= 0 and R < n and C < n and dist[R][C] == -1){
								dist[R][C] = dist[RR][CC] + 1;
								q.push(mp(R, C));
								if(c[R][C] == '3'){
									mini = min(mini, dist[R][C]);
								}
							}
						}
					}
					ans = max(ans, mini);
					for(int i = 0 ; i < n ; i ++)
						for(int j = 0 ; j < n ; j ++){
							dist[i][j] = -1;
						}
				}
			}
		}
		cout << ans << endl;
	}
}

int main(){
	//freopen("input.in" , "r" , stdin);
	solve();
}
