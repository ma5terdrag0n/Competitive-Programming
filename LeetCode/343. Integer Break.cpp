class Solution {
public:
    int integerBreak(int n) {
        int a[n+1] = {0};
        a[1] = a[2] = 1;
        for(int i = 3 ; i <= n ; i++){
            for(int j = 1 ; j < i ; j++){
                a[i] = max(a[i], max(a[j]*a[i-j], max(j * a[i-j], max(a[j] * (i - j), j * (i-j)))));
            }
        }
        return a[n];
    }
};
