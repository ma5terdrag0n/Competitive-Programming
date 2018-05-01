/*
*  Author : pritish.thakkar 
*  Hint : simple dp ( LIS ) but implementation is bit difficult !!
*/
#include<bits/stdc++.h>
#define pb push_back
#define mkp make_pair
#define inf 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define fr first
#define sc second
using namespace std;
typedef unsigned long long ull;
typedef  long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
  
ll n,k;
 
struct frame{
    vi vec;
};
 
int comp(frame a, frame b){
    for(int i=0;i<k;i++){
        if(a.vec[i] < b.vec[i]){
            return 1;
        }
        else if(a.vec[i] > b.vec[i]){
            return 0;
        }
    }
    return 1;
}
 
void solve(){
   while(cin>>n>>k){
    const ll num = k+10;
    struct frame v[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            ll x;
            cin>>x;
            v[i].vec.pb(x);
        }
        sort(v[i].vec.begin(),v[i].vec.end());
        v[i].vec.pb(i);
    }
 
    sort(v, v + n, comp);
 
    ll dp[n];
    ll lastFriend[n];
    for(int i=0;i<n;i++){
        dp[i] = 1LL;
        lastFriend[i] = -1LL;
    }
    ll ans = 0, index = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            // check fitting of box j in box i
            bool fit = 1;
            for(int l = 0 ; l < k; l++ ){
                if(v[j].vec[l] >= v[i].vec[l]){
                    fit = 0;
                    break;
                }
            }
            if(fit){
                if(dp[i] < dp[j]+1)
                    dp[i] = (dp[j] + 1), lastFriend[i] = j; 
 
            }
        }
        if(dp[i] > ans){
            ans = dp[i];
            index = i;
        }
    }
    cout<<ans<<endl;
    vi output;
    output.pb(index);
    while(lastFriend[index] != -1){
        output.pb(lastFriend[index]);
        index = lastFriend[index];
    }
    for(int i=output.size()-1; i>=0; i--){
        cout<<v[output[i]].vec[k] + 1<<" ";
    }
    cout<<endl;
 
   }
 
}
  
 
int main(){
std::ios::sync_with_stdio(0);
solve();
}  
