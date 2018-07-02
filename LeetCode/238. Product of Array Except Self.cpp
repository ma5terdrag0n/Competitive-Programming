class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v(nums.size());
        for(int i = 0 ; i < nums.size() ; i++){
            if(!i){
                v[i] = 1;
            }else{
                v[i] = v[i-1] * nums[i-1];
            }
        }
        int right = 1;
        for(int i = nums.size()-1 ; i >= 0 ; i --){
            v[i] = v[i] * right;
            right *= nums[i];
        }
        return v;
    }
};
