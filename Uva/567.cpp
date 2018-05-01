/*
*  Author : pritish.thakkar 
*/
#include<bits/stdc++.h>
#define pb push_back
#define mkp make_pair
#define inf 10000000070000
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

// ------------------------------------------
    
void solve(){
    ll n;
    map<ll,vi > AdjList;
    ll count=0;
    while(cin>>n){
        AdjList.clear();
       for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        AdjList[x].pb(1LL);
        AdjList[1].pb(x);
       }
       for(int i=2;i<=19;i++){
            cin>>n;
            for(int j=0;j<n;j++){
                ll x;
                cin>>x;
                AdjList[x].pb(i);
                AdjList[i].pb(x);
           }
       }
       cin>>n;
       cout<<"Test Set #"<<++count<<endl;
       while(n--){
            ll a,b;
            cin>>a>>b;
            queue<ll> q;
            q.push(a);
            map<ll,ll> dist;
            dist[a] = 0;
            while(!q.empty()){
                ll u = q.front();
                q.pop();
                for(int i=0;i<AdjList[u].size();i++){
                    int v = AdjList[u][i];
                    if(!dist.count(v)){
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            if(a<10){
                cout<<" "<<a<<" to ";
            }else{
                cout<<a<<" to ";
            }
            if(b < 10){
                cout<<" "<<b<<": ";
            }else{
                cout<<b<<": ";
            }
            cout<<dist[b]<<endl;
       }
       cout<<endl;
    }
}
 
 
//-----------------------------------------------------------------------------------------------------------------------------
int main(){
    std::ios::sync_with_stdio(0);
    solve();
}  
 
