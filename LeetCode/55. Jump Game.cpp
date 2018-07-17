class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dp[nums.size()] = {0};
        int n = nums.size();
        int maxlen = 0;
        dp[0] = 1;
        for(int i  = 0 ; i < nums.size() ; i++){
            if(dp[i] and i + nums[i] > maxlen){
                for(int j = maxlen; j <= i + nums[i] and  j < n; j++){
                    dp[j]=1;
                }
                maxlen = i + nums[i];
            }
        }
        return dp[n-1];
    }
};
