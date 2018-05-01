/*
*   author @Pritish Thakkar/JARVIS !
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

// i am a player !
/*
ll sieve_size;
bitset <1000010> bs;
vector<ll> primes;
void sieve(ll upperbound){
	sieve_size=upperbound+1;
	bs.reset(),bs.flip();//set all nos. to 1
	bs.set(0,false);bs.set(1,false);//except 0 ans 1
	for(ll i=2;i<=sieve_size;i++){
   	 	if(bs.test((size_t)i)){
    	    for(ll j=i*i;j<=sieve_size;j+=i){
    	        bs.set((size_t)j,false);
     	   }
      	  primes.push_back((ll)i);
      	}
    }
}
*/
map<ll, vector<ll> > G;
bool isBipartite(ll V){
    ll colorArr[V+1];
    for (int i = 0; i <= V; ++i)
        colorArr[i] = -1;
    for(ll k=1; k<=V ;++k){
 	 	if(colorArr[k] == -1){
  		  queue <ll> q;
   		  q.push(k);
 		  colorArr[k] = 1;
    	  while (!q.empty()){
        	int u = q.front();
        	q.pop();
        	for (vector<ll>::iterator it=G[u].begin();it!=G[u].end();it++){
            		if (colorArr[*it] == -1){
                		colorArr[*it] = 1 - colorArr[u];
                		q.push(*it);
            		}
            		else if (colorArr[*it]== colorArr[u])
                		return false;
        		}
    	  	}
          }
     }
     return true;
}
 

 void start(){
 	ll t;
 	cin>>t;
 	ll counter=0;
 	while(t--){
 	G.clear();
 	ll n,m;
 	cin>>n>>m;
	for(int i=0;i<m;i++){
 		ll x,y;
 		cin>>x>>y;
 		G[x].pb(y);
 		G[y].pb(x);
 	}
 	cout<<"Scenario #"<<++counter<<":\n";
 	isBipartite(n) ? cout << "No suspicious bugs found!\n" : cout << "Suspicious bugs found!\n";
 	}
 }
int main(){
	std::ios::sync_with_stdio(0);
	start();
	return 0;
 }
