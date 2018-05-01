#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define inf 1000000007
#define fr first
#define sc second
#define eps 1e-15
#define sni(x) scanf("%d",&x)
#define snl(x) scanf("%lld", &x)
#define snc(x) scanf("%c", &c);
#define rep(i, n) for(int i = 0 ; i < n ;i ++)
#define FOR(i, x, y) for(int i = x ; i < y ; i ++)
#define DEC(i, x, y) for(int i = x ; i >= y ; i --)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

bool isLower(char c){
    return (c <= 'z' and c >= 'a');
}

template<typename c>
int binary_search(c *a, int lo, int hi, c key){
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(a[mid] == key){
            return mid;
        }else if(a[mid] < key){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return -1;
}

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

string toLowerCase(string s){
    rep(i, s.size()){
        if(!isLower(s[i])){
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}

//--------------------------------------------------------------------

map<ll, vii> adj;
map<ll, ll> dist1, dist2;
priority_queue<ii, vector<ii>, greater<ii> > pq;
map<ll, vii> rev;

map<ll, ll> dijkstra(map<ll, vii> &graph){
    map<ll,ll> dist;
    dist.clear();
    pq.push(mp(0,1));
    dist[1] = 0;
    while(!pq.empty()){
        ll d = pq.top().fr;
        ll u = pq.top().sc;
        pq.pop();
        if(d != dist[u]){
            continue;
        }
        for(int i = 0 ; i < graph[u].size() ; i ++){
            ll v = graph[u][i].fr;
            ll z = graph[u][i].sc;
            if(!dist.count(v) or dist[v] > dist[u] + z){
                dist[v] = dist[u] + z;
                pq.push(mp(dist[v], v));
            }
        }
    }
    return dist;
}

void solve(){
    ll t;
    cin >> t;
    while(t--){
        adj.clear();
        rev.clear();
        ll n, m;
        cin >> n >> m;
        for(int i = 0 ; i < m ; i ++){
            ll u, v, wt;
            cin >> u >> v >> wt;
            adj[u].pb(mp(v, wt));
            rev[v].pb(mp(u, wt));
        }
        dist1 = dijkstra(adj);
        dist2 = dijkstra(rev);
        ll ans = 0;
        for(map<ll,ll>::iterator it = dist1.begin() ; it != dist1.end() ; it++){
            ans += it->sc + dist2[it->fr];
        }       
        cout << ans << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    solve();
}
