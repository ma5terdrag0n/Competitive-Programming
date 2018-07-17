class Solution {
public:
    vector<vector<int> > v;
    
    void fun(vector<int> nums, vector<int> x, int idx){
        if(idx >= nums.size())return;
        for(int i = idx ; i < nums.size() ;i++){
            x.push_back(nums[i]);
            v.push_back(x);
            fun(nums, x, i+1);
            x.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
    
        vector<int> tmp;
        v.push_back(tmp);
        fun(nums, tmp, 0);
        return v;
    }
};
