class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v;
        v.push_back(0);
        if(num==0)return v;
        v.push_back(1);
        if(num == 1)return v;
        v.push_back(1);
        if(num == 2)return v;
        for(int i = 3 ; i <= num ; i++){
            if(i&1){
                v.push_back(v[i/2]+1);
            }else{
                v.push_back(v[i/2]);
            }
        }
        return v;
    }
};
