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
            if(a[i] < a[i-1])continue;
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
    
    int factorial(int n){
        if(n==1)return 1;
        return n*factorial(n-1);
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int counter = 0;
        vector<vector<int>> v(factorial(nums.size()));
        do{
            for(int i = 0 ; i < nums.size();i++){
                v[counter].push_back(nums[i]);
            }
            counter++;
        }while(next_permutation(nums));
        return v;
    }
};
