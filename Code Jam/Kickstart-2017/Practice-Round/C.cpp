/*
*  Author : __daemon 
*/
#include<bits/stdc++.h>
#define pb push_back
#define mkp make_pair
#define inf 1000000009
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
 
void clr(ll *a,ll val){
  memset(a,val,sizeof(a));
}
 
void solve(){
freopen("a.txt","r",stdin);
freopen("out.txt","w",stdout);  
ll t,cas=0;
cin>>t;

for(int iii=1;iii<=t;iii++){
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    n = min(n,m);
    ans = n*(n+1)/2LL;
    printf("Case #%d: %lld\n", iii,ans);
 }
}
int main(){
  solve();
} 
