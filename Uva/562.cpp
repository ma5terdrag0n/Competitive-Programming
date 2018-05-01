/*
*   Code By : Pritish Thakkar ## JARVIS !
*/
#include <bits/stdc++.h>
#define min_3(a,b,c) (min((a),min((b),(c))))
#define SET(a) memset(a,-1,sizeof(a))
#define all(a) a.begin(),a.end()
#define clr(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define mkp make_pair
#define pi acos(-1.0)
#define inf 1000000007
#define ninf -1000000007
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define TEST int t;cin>>t;while(t--)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<ii> vi;
typedef map<ll,vv> gg;

//Translator
bool isUpperCase(char c){return c>='A' && c<='Z';}//NOTES:isUpperCase
bool isLowerCase(char c){return c>='a' && c<='z';}//NOTES:isLowerCase
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}//NOTES:isLetter
bool isDigit(char c){return c>='0' && c<='9';}//NOTES:isDigit
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}//NOTES:toLowerCase
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}//NOTES:toUpperCase
bool isAlpha(char c){return isUpperCase(c)||isLowerCase(c);}//NOTES:isaplhabet or not

template <typename T>T modpow(T base,T exp, T modulus){base %= modulus;T result = 1;while (exp > 0) {if (exp & 1) result = (result * base) % modulus;base = (base * base) % modulus;exp >>= 1;}return result;}

ll gcd(ll a,ll b) {
    return b==0?a:gcd(b,a%b);
}

ll sod(ll n){ll sum = 0;while(n){sum+=n%10;n/=10;}return sum;} // sum of digits !!
ll binary_search(ll *a,ll start,ll end,ll toFind){
	ll mid = (start+end)>>1;
	if(start < end){if(a[mid] == toFind)return mid;else if(a[mid] < toFind)return binary_search(a,mid+1,end,toFind);else if(a[mid] > toFind)return binary_search(a,start,mid,toFind);}
	return -1;
}


int main() {
  std::ios::sync_with_stdio(0);
  ll counter=0;
	TEST{
		ll n;
		cin>>n;
		ll a[n];
		ll i,j,sum=0;
		rep(i,n){
			cin>>a[i];
			sum+=a[i];
		}
		ll x = sum/2;
		ll dp[n+1][x+1];
		rep(i,n+1) dp[i][0] = 0;
		rep(i,x+1) dp[0][i] = 0;
		for(ll i=1;i<n+1;i++){
			for(ll j=1;j<x+1;j++){
				if(j < a[i-1])
					dp[i][j] = dp[i-1][j];
				else dp[i][j] = max(dp[i-1][j],a[i-1]+dp[i-1][j-a[i-1]]);
			}
		}
		rep(i,n+1){
			rep(j,x+1) cout<<dp[i][j]<<" ";
			cout<<endl;
		}
		ll ret = dp[n][x];
		cout<<abs(sum-2*ret)<<endl;
	}
    return 0;
}
