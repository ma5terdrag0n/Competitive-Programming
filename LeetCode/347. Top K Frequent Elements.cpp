class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        vector<pair<int, int> > v;
        for(int i = 0 ; i < nums.size() ; i++){
            m[nums[i]]++;
        }
        for(auto x: m){
            v.push_back({x.second, x.first});
        }
        sort(v.rbegin(), v.rend());
        vector<int> ret;
        for(int i = 0 ; i < k ; i ++){
            ret.push_back(v[i].second); 
        }
        return ret;
    }
};
