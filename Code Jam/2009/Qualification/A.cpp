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
    freopen("a.txt","r",stdin);
    freopen("o.txt","w",stdout);
   	ll l,d,n;
   	cin>>l>>d>>n;
   	string s[d];
   	ll i,j;
   	char a[d][l],b[d][l];
   	rep(i,d)
   		cin>>s[i];
   	rep(i,d){
   		rep(j,l){
   		   a[i][j] = s[i][j];
   		}
   	}
   	ll counter=0;
   	while(n--){
   		for(ll i=0;i<d;i++)
   			for(ll j=0;j<l;j++)
   				b[i][j] = a[i][j];
   		string str;
   		cin>>str;
   		vector<set<char> > v(l);
   		ll fish=0;
		for(ll i=0;i<str.size();){
			if(str[i] == '('){
				i++;
				while(str[i] != ')'){
					v[fish].insert(str[i]);
					i++;
				}
				fish++;
			}
			while(isAlpha(str[i])){
				v[fish].insert(str[i]);
				i++;
				fish++;
			}
			if(str[i] == ')')
				i++;
		} 
		ll ans=inf;
		for(ll i=l-1;i>=0;i--){
			ll dick=0;
			for(char j='a';j<='z';j++){
				for(ll mo=0;mo<d;mo++){
					if(v[i].count(j) && b[mo][i]==j){
						dick ++;
						b[mo][i] = '1';
					}
				}
			}
			
			for(ll mo=0;mo<d;mo++){
				if(b[mo][i]!='1')
					for(ll no=0;no<l;no++){
						b[mo][no] = '0';
					}
			}
			ans = min(ans,dick);
		}
		cout<<"Case #"<<++counter<<": "<<ans<<endl;
   	}
    return 0;
}
