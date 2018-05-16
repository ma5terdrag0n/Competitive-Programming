// See this for more beautiful code:
// https://leetcode.com/problems/minimum-size-subarray-sum/solution/#
// My approach is also 2 pointer approach but the way it is 
// implemented in above code is awesome.

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        int sum[n] = {0};
        sum[0] = nums[0];
        for(int i = 1 ; i < n ; i ++){
            sum[i] = nums[i] + sum[i-1];
        }
        if(sum[n-1] < s) return 0;
        int i, j;
        i = j = 0;
        int ans = INT_MAX;
        while(i < n && j < n && i <= j){
            while(j < n){
                if(i && sum[j] - sum[i-1] < s){
                    j++;
                }else if(i == 0 && sum[j] < s){
                    j++;
                }else{
                    break;
                }
            }
            while(i <= j && sum[j] - sum[i] >= s){
                i++;
            }
                
            ans = min(ans, j-i+1);
            j++;
            if(j >= n)break;
        }
        return ans;
    }
};
