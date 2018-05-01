/*
*  Author : __daemon 
*  Hint : Simple even-odd Problem
*/
#include<bits/stdc++.h>
#define pb push_back
#define mkp make_pair
#define inf 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define fr first
#define sc second
#define clr(a) memset(a,0LL,sizeof a);
#define sn(t) scanf("%lld",&t)
#define pn(t) printf("%lld",t)
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
bool isUpper(char c) {return (c >= 'A' && c <= 'Z');}
bool isLower(char c) {return (c >= 'a' && c <= 'z');}
bool isalpha(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z');}
bool isalnum(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z')||(c >= '0' && c <= '9');}
char toUpper(char c){return isUpper(c)?c:c-'a'+'A';}
char toLower(char c){return isLower(c)?c:c+'a'-'A';}

ll modpow(ll base,ll exp,ll mod){
  ll ret=1;
  base=base%mod;
  while(exp){
    if(exp&1)ret *= base ;
    base *= base;
    exp>>=1LL;
  }
  return ret;
}

void solve(){
  freopen("a.txt","r",stdin);
  freopen("b.txt","w",stdout);
	ll counter=0;
	ll t;
	cin>>t;
	ll h[2501];
	for(int d=0;d<t;d++){
		memset(h,0,sizeof h);
		ll n;
		cin>>n;
		ll a[2*n][n];
		ll i,j;
		vi v;
		rep(i,2*n-1){
			rep(j,n){
				cin>>a[i][j];
				++h[a[i][j]];
			}
		}
		rep(j,2501LL){
			if(h[j]&1){
				v.pb(j);		
			}
		}
		sort(v.begin(),v.end());
		cout<<"Case #"<<d+1<<": ";
		rep(i , v.size()-1){
			cout<<v[i]<<" ";
		}
		cout<<v[v.size()-1]<<endl;
	}
	 
	
	
}

int main(){
  std::ios::sync_with_stdio(false);
  solve();
} 
