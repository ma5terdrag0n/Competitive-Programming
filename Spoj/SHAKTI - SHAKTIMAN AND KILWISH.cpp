#include<bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long ll;

void solve(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		bool ok = 1;
		if(n&1){
			ok=0;
		}
		if(ok){
			printf("%s\n", "Thankyou Shaktiman");
		}else{
			printf("%s\n", "Sorry Shaktiman");
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	solve();
}
