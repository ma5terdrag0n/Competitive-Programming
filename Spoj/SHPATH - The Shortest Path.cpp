#include<bits/stdc++.h>
#include <cstdio> 
#include <cstdlib> 
#include <iostream>
#include <ctime>
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
//.............................................

//....@typedef....................
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<ii> vi;
typedef map<ll,vv> gg;
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
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
ll sod(ll n){ll sum = 0;while(n){sum+=n%10;n/=10;}return sum;} // NOTE: sum of digits !!
ll binary_search(ll *a,ll start,ll end,ll toFind){
	ll mid = (start+end)>>1;
	if(start < end){if(a[mid] == toFind)return mid;else if(a[mid] < toFind)return binary_search(a,mid+1,end,toFind);else if(a[mid] > toFind)return binary_search(a,start,mid,toFind);}
	return -1;
}
//.................................................................................
map<ll,vi> adj;
int main(){
	std::ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		adj.clear();
		ll V;
		cin>>V;
		ll flag=0;
		string s[V];
		map<string ,ll> mop;	
		while(flag<V){
			cin>>s[flag];
			mop[s[flag]] = flag;
			ll cit;
			cin>>cit;
			while(cit--){
				ll c,b;
				cin>>b>>c;
				b--;
				adj[flag].pb(mkp(b,c));
			}
			flag++;
		}
		ll qq;
		cin>>qq;
		while(qq--){
			ll S,D;
			string s1,s2;
			cin>>s1>>s2;
			S = mop[s1];
			D = mop[s2];
			vv dist(V,2*inf);
    		dist[S] = 0;
    		priority_queue<ii,vi,greater<ii> > pq;
    		pq.push(ii(0,S));
    		while(!pq.empty()){
    			ii top = pq.top();
    			pq.pop();
    			ll d,u;
    			d = top.first;
    			u = top.second;
    			if(u == D)
					break;
    			if(d == dist[u])
    				for(ll i=0;i<adj[u].size();i++){
    					ll v = adj[u][i].first,weight = adj[u][i].second;
    					if(dist[u] + weight < dist[v]){
    						dist[v] = dist[u] + weight;
    						pq.push(ii(dist[v],v));
    					}
    				}
    		}
    		cout<<dist[D]<<endl;
		}
	}
}
