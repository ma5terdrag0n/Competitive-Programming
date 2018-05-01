#include<bits/stdc++.h>
#define         pb                      push_back
#define         mkp                     make_pair
#define         inf                     1000000007
#define         REV(i, x, y)            for(int i = x ; i >= y ; i-- )
#define         FOR(i, x, y)            for(int i = x ; i <= y ; i++ )
#define         rep(i, n)               for(int i = 0 ; i < n ; i++  )
#define         clr(a)                  memset(a,0LL,sizeof a);
#define         all(v)                  v.begin(), v.end()
#define         filein                  freopen("input.in" , "r" , stdin)
#define         fileout                 freopen("output.out" , "w" , stdout)
 
using           namespace               std;
  
typedef         unsigned long long      ull;
typedef         long long               ll;
typedef         vector<ll>              vi;
typedef         pair<ll,ll>             ii;
 
 
ll k, n;
ll a[100001];
ll fun(){
    ll ret = 0;
    for(int i = 0 ; i < n ; i ++){
        while(i < n  and k - a[i] > 0){
            k -= a[i];
            i ++;
            ret ++;
            cerr << a[i] << " " << ret << " " << k << endl;
        }
        if(i < n - 1 and ret > 0){
            k += a[n - 1];
            ret --;
            n --;
            i--;
        }
 
    }
    return ret;
}
 
 
void solve(){
    ll t;
    cin >> t;
    for(int i = 1 ; i <= t ; i ++){
        cin >> k >> n;
        for(int j = 0 ; j < n ; j ++){
            cin >> a[j];
        }    
        sort(a, a + n);
        cout << "Case #" << i << ": ";
        cout << fun() << endl;
    }
}
 
//________________________________
  
void donuts(){
    filein; 
    fileout;
}
  
int main(int argc, char *argv[]){
    std::ios::sync_with_stdio(0);
    donuts();
    solve();
}
