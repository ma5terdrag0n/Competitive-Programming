class Solution {
public:
    bool next_permutation(vector<int>& a){
        bool ok = 0;
        int n = a.size();
        for(int i = 1 ;i < n ; i++){
            if(a[i] > a[i-1]){
                ok=1;
                break;
            }
        }
        if(ok==0)return 0;
        int idx = 0;
        for(int i = n - 1 ; i > 0 ; i--){
            if(a[i] <= a[i-1])continue;
            idx = i-1;
            break;
        }
        int max_index = 0;
        int max_value = 100000;
        for(int i = idx+1 ; i < n ; i ++){
            if(a[i] > a[idx] && a[i] < max_value){
                max_value = a[i];
                max_index = i;
            }
        }
        swap(a[idx], a[max_index]);
        vector<int> v;
        for(int i = idx+1;i<n;i++){
            v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        idx++;
        for(int i = 0 ; i < v.size() ; i ++){
            a[idx++] = v[i];
        }
        return 1;
    }
    
    void nextPermutation(vector<int>& nums) {
        bool ok = next_permutation(nums);
        if(ok==0){
            sort(nums.begin(), nums.end());
        }
    }
};
