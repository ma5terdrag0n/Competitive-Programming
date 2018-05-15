class Solution {
public:
    bool isPerfect(int n){
        int x = sqrt(n);
        return (x*x == n);
    }
    int numSquares(int n) {
        int dp[n+1];
        for(int i = 0 ; i <= n ; i ++){
            dp[i] = 1000000;
            
        }
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2 ; i <= n ; i ++){
            if(isPerfect(i)){
                dp[i] = 1;
                continue;
            }
            for(int j = 1; j*j < i ; j ++){
                dp[i] = min(dp[i], 1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};
