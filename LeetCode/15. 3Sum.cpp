class Solution {
public:
    int f[2000001] = {0};
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int> > v;
        
        for(int i = 0 ; i < nums.size() ; i++){
            f[nums[i] + 1000000] = i;
        }    
        
        for(int i = 0 ; i < nums.size() ; i ++){
            if(i && nums[i-1] == nums[i])continue;
            for(int j = i + 1 ; j < nums.size() ; j++){
                if(j > i+1 && nums[j] == nums[j-1])continue;
                int k = nums[i]  + nums[j];
                k = -k;
                if(f[k + 1000000] > j){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(k);
                    v.push_back(tmp);
                }
            }
        }
        return v;
        
    }
};
