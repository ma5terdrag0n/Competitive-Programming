#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve(){
    int k, l, n;
    scanf("%d%d%d",&k,&l,&n);
    int dp[1000000] = {0};
    if( k > l ){
        swap(k, l);
    }
    for(int i = 1; i < 1000001 ; i ++){
        if(i < k and i < l){
            dp[i] = (i & 1);
        }else if(i >= k and i < l){
            dp[i] = ((dp[i - k] == 0) or (dp[i - 1] == 0));
        }else if(i >= l){
            dp[i] = ((dp[i - k] == 0) or (dp[i - 1] == 0) or (dp[i - l] == 0));
        }
    }
    for(int i = 0 ; i < n ;i ++){
        int x;
        scanf("%d", &x);
        printf("%c", (dp[x] == 1) ? 'A' : 'B');
    }

}


int main(){
    freopen("input.in", "r" , stdin);
    int t = 1;
    // scanf("%d",&t);
    for(int ii = 0 ; ii < t ; ii ++){
        solve();
    }
}
