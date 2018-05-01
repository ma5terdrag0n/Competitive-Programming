/*
*  Author : pritish.thakkar 
*  Hint : LIS (dp) variant, 
*  > First of all understand the Ranking process.
*  > Do not get confused with ranking and ordering.
*  > The input array A[1..n] here means that the event 
*    i occurs at position A[i] in the correct sequence.  
*    1 <= i <= n
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
#define WHITE 0
#define BLACK 1
using namespace std;
typedef unsigned long long ull;
typedef  long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
  
void solve(){
       string s;
       cin>>ws;
       ll n;
       map<ll,ll> m;
       while(getline(cin,s)){
              vi v;
              ll x;
              istringstream dss(s);
              while(dss>>x){
                     v.pb(x);
              } 
              if(v.size() == 1){
                     n = v[0];
                     getline(cin,s);
                     istringstream iss(s);
                     m.clear();
                     ll i = 0;
                     while(iss>>x){
                            m[++i] = x;
                     }
                     continue;
              }
               
              ll a[n+1];
              for(int i=0;i<v.size();i++){
                     a[v[i]] = i+1; 
              }
 
              for (int i = 0; i < n; ++i){
                     v[i] = a[i+1];
              }
 
              ll dp[n];
              ll ans=0;
              for(int i=0;i<n;i++)
                     dp[i] = 1LL;
              for(int i=0;i<n;i++){
                     for(int j=0;j<i;j++){
                            if(m[v[i]] > m[v[j]]){
                                   dp[i] = max(dp[i], dp[j] + 1);
                            }
                     }
                     ans = max(dp[i], ans);
              }
              cout<<ans<<endl;
       }
}
  
int main(){
std::ios::sync_with_stdio(0);
solve();
}  
