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
  ll n;
  cin>>n;
  string ans,s[n];
  ll a[n];
  set<char> se;
  ll maxi=0;
  cin>>ws;
  for(int i=0;i<n;i++){
    se.clear();
    getline(cin,s[i]);
    for(int j=0;j<s[i].size();j++){
      if(isalpha(s[i][j]))
      se.insert(s[i][j]);
    }
    
    a[i] = se.size();
    if(a[i] > maxi){
      ans=s[i];
      maxi=a[i];  
    }
    if(a[i] == maxi){
      ans = min(ans,s[i]);
    }
  }
  cout<<"Case #"<<iii<<": "<<ans<<endl;
}
}
 
int main(){
  solve();
} 
