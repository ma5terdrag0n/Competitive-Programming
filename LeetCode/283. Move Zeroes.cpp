class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lo, hi;
        lo = hi = 0;
        while(lo < nums.size() && hi < nums.size() && lo <= hi){
            while(lo < nums.size() && nums[lo])lo++;
            hi = lo+1;
            while(hi < nums.size() && nums[hi] == 0)hi++;
            if(hi < nums.size()){
                swap(nums[hi], nums[lo]);
                hi++;
                lo++; 
            }
        }
    }
};
