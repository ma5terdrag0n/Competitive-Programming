class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum, tmpSum;
        maxSum = tmpSum = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            tmpSum += nums[i];
            tmpSum = max(tmpSum, nums[i]);
            maxSum = max(maxSum, tmpSum);
        }
        return maxSum;
    }
};
