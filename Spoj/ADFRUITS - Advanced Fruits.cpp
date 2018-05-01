#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[123][123];

string lcs(string a, string b){
    ll asize = a.size();
	ll bsize = b.size();
	string ret = "";
	vector<char> v;
	memset(dp,0,sizeof dp);
	for(int  i = 1 ; i <= asize ; i ++){
		for(int  j = 1 ; j <= bsize ; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;	
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
// ****UNCOMMENT TO SEE MEMO TABLE****  
//	for(int i = 0 ; i <= asize ; i++){
//		for(int j = 0 ; j <= bsize ; j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	ll x,y;
	x = asize;
	y = bsize;
	while(true){
		if(x == 0LL || y == 0LL){
			break;
		}
		if(a[x-1] == b[y-1]){
			v.push_back(a[x-1]);
			x--;y--;
		}else{
			dp[x-1][y] >= dp[x][y-1] ? (x--) : (y--);
		}
	}
	for(int i = v.size() - 1 ; i >= 0 ; i--){
		ret.push_back(v[i]);
	}
	return ret;
}


int main(){
	string a,b;
	while(cin>>a>>b){
		string common = lcs(a,b);
		ll j,k;
		j = k = 0;
		for(int i = 0 ; i <= common.size() ; i ++){
			for(;j<a.size();j++){
				if(a[j] == common[i]){
					j++;
					break;
				}else{
					cout<<a[j];
				}
			}
			for(;k<b.size();k++){
				if(b[k] == common[i]){
					k++;
					break;
				}else{
					cout<<b[k];
				}
			}
			cout<<common[i];
		}
		cout<<endl;
		
	}
	
}
