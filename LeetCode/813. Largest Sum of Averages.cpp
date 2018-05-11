/*
* This is a top down approach but bottom up approach is much better in terms of memory which
* you can see on this webpage https://leetcode.com/problems/largest-sum-of-averages/solution/
*/

// dp[i][j][k] means the solution if the array is from index i to index j and 
// we can partition it into k subparts.
// dp[0][n-1][k] will give the desired answer then, for this problem.

double dp[111][111][111] = {0};

class Solution {
public:
    double rest(int *a, int start, int end){
        if(start-1 < 0){
            return (double)a[end] / (end-start+1);
        } else{
            double ans = (double)1.00 * (a[end] - a[start-1]) / (end-start+1);
            return ans;
        }
    }
    
    double recursion(vector<int> & a, int I, int J, int k){
        if(dp[I][J][k] != 0.00) return dp[I][J][k];
        if(k == 1){
            int sum = 0, counter = 0;
            for(int i = I ; i < J ; i++){
                sum += a[i];
                counter++;
            }
            return dp[I][J][k] = (double)1.00 * sum / counter;
        }
        int sum[a.size()] = {0};
        for(int i = 0 ; i < a.size() ; i++){
            if(!i){
                sum[i] = a[i];
            }else{
                sum[i] = a[i] + sum[i-1];
            }
        }
        double ans = 0;
        for(int i = I+1; i < J ;i++){
            ans = max(ans, recursion(a, i, J, k-1) + rest(sum, I, i-1));
        }
        return dp[I][J][k] = ans;
    }
    
    double largestSumOfAverages(vector<int>& A, int K) {
        for(int i = 0 ; i <= A.size() ;i++){
            for(int j = 0 ; j <= A.size() ;j++){
                for(int k = 0 ; k <= K ; k ++){
                    dp[i][j][k] = 0.00;
                }
            }
        }
        return recursion(A, 0, A.size(), K);
    }
};
