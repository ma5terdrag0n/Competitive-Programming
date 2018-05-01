/*
*   author @Pritish Thakkar/JARVIS !
http://www.spoj.com/problems/EBOXES/
*/
#include <bits/stdc++.h>
 
//...........MACROS............................
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
#define print(i) printf("%lld\n",i)
#define WHITE 0
#define BLACK 1
using namespace std;
//.............................................
 
//....@typedef....................
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
//typedef map<ll,vll> gg;
//...............................
 
//.............Translator.................................................
bool isUpperCase(char c){return c>='A' && c<='Z';}//NOTES:isUpperCase
bool isLowerCase(char c){return c>='a' && c<='z';}//NOTES:isLowerCase
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}//NOTES:isLetter
bool isDigit(char c){return c>='0' && c<='9';}//NOTES:isDigit
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}//NOTES:toLowerCase
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}//NOTES:toUpperCase
bool isAlpha(char c){return isUpperCase(c)||isLowerCase(c);}//NOTES:isaplhabet or not
//NOTE : long long to string 
string toString(ll n){vector<ll>  v;while(n){v.pb(n%10);n/=10;}reverse(v.begin(),v.end());string s="";ll i;rep(i,v.size()){s.pb(v[i]+'0');}return s;}
//..........................................................................
 
//.................................GPFNS......................................
template <typename T>T modpow(T base,T exp, T modulus){base %= modulus;T result = 1;while (exp > 0) {if (exp & 1) result = (result * base) % modulus;base = (base * base) % modulus;exp >>= 1;}return result;}
ull gcd(ull a,ull b) {return b==0?a:gcd(b,a%b);}
ull lcm(ull a,ull b){return a*(b/gcd(a,b));}
ll sod(ll n){ll sum = 0;while(n){sum+=n%10;n/=10;}return sum;} // NOTE: sum of digits !!
ll binary_search(ll *a,ll start,ll end,ll toFind){
	ll mid = start+(end-start)/2;
	if(start <= end){if(a[mid] == toFind)return mid;else if(a[mid] < toFind)return binary_search(a,mid+1,end,toFind);else if(a[mid] > toFind)return binary_search(a,start,mid-1,toFind);}
	return -1;
}
//.................................................................................

priority_queue<pair<ll,ii> > EdgeList;
ll SET[1000000];
int findSet(ll a){
	if(SET[a] == a)
		return a;
	return findSet(SET[a]);
}
bool isSameSet(ll a,ll b){
	return findSet(a) == findSet(b);
}
void unionSet(ll a,ll b){
	SET[findSet(a)] = findSet(b);
}
void start(){
		ll p,n,m;
		p=1;
		cin>>n>>m;
		ll i;
		rep(i,n)
			SET[i] = i;
		for(int i=0;i<m;i++){
			ll a,b,c;
			cin>>a>>b>>c;
			EdgeList.push(mkp(-1*c*p,mkp(a,b)));
		}
		ll mst_cost=0;
		while(!EdgeList.empty()){
			pair<ll,ii> front = EdgeList.top();
			EdgeList.pop();
			if(!isSameSet(front.second.first , front.second.second)){
				mst_cost += -1*front.first;
				unionSet(front.second.first , front.second.second);
			}
		}
		cout<<mst_cost<<endl;

}
int main(){
	std::ios::sync_with_stdio(0);
	start();
	return 0;
}
