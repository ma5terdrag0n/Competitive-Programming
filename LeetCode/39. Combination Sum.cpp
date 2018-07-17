class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int index = 0) {
        vector<vector<int> > ret;
        if(target <= 0)return ret;
        for(int i = index ; i < candidates.size() ; i++){
            if(target > candidates[i]){
                vector<vector<int> > tmp = combinationSum(candidates, target - candidates[i], i);
                if(!tmp.empty()){
                    for(int j= 0 ; j < tmp.size() ;j++){
                        tmp[j].push_back(candidates[i]);
                        ret.push_back(tmp[j]);
                    }
                }
            }else if(target == candidates[i]){
                vector<int> v;
                v.push_back(target);
                ret.push_back(v);
            }
        }
        return ret;
    }
};
