/*
*  Author : pritish.thakkar 
*/

#include<bits/stdc++.h>
#define     pb                      push_back
#define     mkp                     make_pair
#define     inf                     1000000007
#define     rep(i,n)                for(int i=0;i<n;i++)
#define     fr                      first
#define     sc                      second
#define     clr(a)                  memset(a,0LL,sizeof a);
#define     pi                      3.141592653589793
#define     gc                      getchar
#define     all(v)                  v.begin(), v.end()
using       namespace               std;

typedef     unsigned long long      ull;
typedef     long long               ll;
typedef     vector<ll>              vi;
typedef     pair<ll,ll>             ii;
typedef     vector<ii>              vii;
typedef     set<ll>::iterator       sit;
typedef     map<ll,ll>::iterator    mit;
typedef     vector<int>::iterator   vit;

template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}

//_____________________________

bool isUpper(char c) {return (c >= 'A' && c <= 'Z');}
bool isLower(char c) {return (c >= 'a' && c <= 'z');}
bool iplpha(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z');}
bool iplnum(char c) {return (c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z')||(c >= '0' && c <= '9');}
char toUpper(char c){return isUpper(c)?c:c-'a'+'A';}
char toLower(char c){return isLower(c)?c:c+'a'-'A';}
template<typename t> t _GCD(t a, t b){return ((b == 0) ? a : _GCD(b, a%b));} 
template<typename t> t _LCM(t a, t b){return (a * (b / _GCD(a, b)));}
ll modpow(ll base, ll expo, ll mod){base  = base % mod;ll ret = 1LL;while(expo > 0){if(expo & 1LL){ret =( ret * base) % mod;}base = (base * base )% mod;expo >>= 1LL;}return ret;}

//______________________________

bool p[1000001];
vi primes;
void sieve(ll n){memset(p,1,sizeof p);p[0] = p[1] = 0;
    for(int i = 2 ; i <= sqrt(n) ; i++){if(p[i]){for(int j = i * i ; j < n ; j+=i){p[j] = 0;}}}
    for(int i = 2 ; i <= n ; i ++){if(p[i]){primes.pb(i);}}}

bool isPrime(ll n){if(n < 1000001){return p[n];}ll ans = 0;for(int i= 0 ; i < primes.size() && primes[i] * primes[i] <= n  ; i ++){if(n % primes[i] == 0){return 0;}}return 1;}
 
//______________________________


struct init{
  ll prob, penalty;
  int id;
  init(ll prob,ll penalty,int id){
    this->prob = prob;
    this->penalty = penalty;
    this-> id = id; 
  }
};

bool comp(init a, init b){
  if(a.prob > b.prob){
    return true;
  }else if(b.prob > a.prob){
    return 0;
  }
  if (a.penalty < b.penalty)
    return true;
  if(a.penalty > b.penalty)
    return false;
  return (a.id < b.id);  
}

void solve(){
  ll t;
  cin >> t;
  while(t--){
    string s;
    int AC[101][10];
    int P[101][10];
    for(int i = 0 ; i < 101 ;i ++){
      for(int j = 0 ; j < 10 ; j ++){
        AC[i][j] = P[i][j] = 0;
      }
    }
    cin >> ws;
    set<int> contestents;
    while(getline(cin, s) && s != ""){
      istringstream is(s);
      int id , qid, tm;
      char verdict;
      is >> id;
      is >> qid;
      is >> tm;
      is >> verdict;
      contestents.insert(id);
      if(verdict == 'C'){
        if(AC[id][qid] == 0){
          AC[id][qid] = 1;
          P[id][qid] += tm;
        }
      }else if (AC[id][qid] == 0 && verdict == 'I'){
        P[id][qid] += 20;
      }
    }
    vector<init> later;
    ii temp[101];
    for(int i = 1 ; i <= 100 ; i ++){
      temp[i].fr = temp[i].sc = 0;
      for(int j = 1 ; j < 10 ; j++){
        if(AC[i][j] == 1){
          temp[i].fr++;
          temp[i].sc += P[i][j];
        }
      }
    }
    for(int i = 1 ; i <= 100 ; i ++){
      later.pb(init(temp[i].fr, temp[i].sc, i));
    }
    sort(all(later), comp);
    for(int i = 0 ;i < later.size() ; i ++){
      if(contestents.count(later[i].id)){
        cout << later[i].id << " " << later[i].prob << " " << later[i].penalty << endl;
      }
    }
    if(t)
    cout << endl;
  }
}
//________________________________

int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(0);
    // freopen("input.in" , "r" , stdin);
    // freopen("output.out" , "w" , stdout);
    solve();
}
