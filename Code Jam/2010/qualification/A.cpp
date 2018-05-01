/*
*  Author : pritish.thakkar 
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
typedef unsigned long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
bool isUpper(char c) {return (c >= 'A' && c <= 'Z');}
bool isLower(char c) {return (c >= 'a' && c <= 'z');}
bool isalpha(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z');}
bool isalnum(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z')||(c >= '0' && c <= '9');}
char toUpper(char c){return isUpper(c)?c:c-'a'+'A';}
char toLower(char c){return isLower(c)?c:c+'a'-'A';}

ll modpow(ll base, ll expo, ll mod){
    base  = base % mod;
    ll ret = 1LL;
    while(expo > 0){
        if(expo & 1LL)
                ret =( ret * base) % mod;
        base = (base * base )% mod;
        expo >>= 1LL;
    }
    return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------
// Enter Your code here


void solve(){
  freopen("in","r",stdin);
  freopen("out","w",stdout);
  ll t;
  cin>>t;
  for(int tt = 1; tt <= t ; tt++){
    ll n,k;
    cin>>n>>k;
    bool ok=0;
    ll rem = 0;
    while(k%2 == 1){
      k>>=1;
      rem++;
    }
    if(rem >= n)
      ok=1;
    cout<<"Case #"<<tt<<": ";
    if(ok){
      cout<<"ON\n";
    }else{
      cout<<"OFF\n";
    }
  }
}

//-----------------------------------------------------------------------------------------------------------------------------
int main(){
    std::ios::sync_with_stdio(false);
    solve();
} 
