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

void solve(){
	ll n;
	cin>>n;
	cin>>ws;
	map<string , ll > listing;
	for(int i=0;i<n;i++){
		string s;
		getline(cin,s);
		string g="";
		ll j=0;
		while(s[j]!=' '){
			g.pb(s[j]);
			j++;
		}
		if(!listing.count(g)){
			listing[g]=1;
		}else{
			listing[g]++;
		}
	}
	for(map<string,ll>::iterator it=listing.begin() ;it!= listing.end() ; it++){
		cout<<it->fr<<" "<<it->sc<<endl;
	}

}

int main(){
	solve();
} 





