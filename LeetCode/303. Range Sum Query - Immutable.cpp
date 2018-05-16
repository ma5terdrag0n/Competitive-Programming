#include<bits/stdc++.h>
    
class NumArray {
public:
    int v[100000];
    
    NumArray(vector<int> nums) {
        if(nums.size()){
            v[0] = nums[0];
            for(int i = 1 ; i < nums.size() ; i++){
                v[i] = v[i-1] + nums[i];
            }
        }
    }
    
    int sumRange(int i, int j) {
        if(i!=0){
            return v[j] - v[i-1];
        }else{
            return v[j];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
