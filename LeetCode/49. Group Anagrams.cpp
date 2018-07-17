typedef long long ll;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n;
        n = strs.size();
        int a[n][26] = {0};
        for(int i = 0 ; i < n ; i++){
            ll x = 0;
            for(int j = 0 ; j  < strs[i].size() ; j++){
                a[i][strs[i][j] - 'a']++;
            }
        }
        bool done[n] = {0};
        vector<vector<string> > ret;
        for(int i = 0 ; i  < n ; i ++){
            if(done[i] == 1)continue;
            done[i] = 1;
            vector<string> v;
            v.push_back(strs[i]);
            
            for(int j = i+1 ; j < n ; j++){
                bool ok = 1;
                for(int k = 0 ; k < 26 ; k++){
                    if(a[i][k] != a[j][k]){
                        ok=0;
                        break;
                    }
                }
                if(ok){
                    done[j] = 1;
                    v.push_back(strs[j]);
                }
            }
            ret.push_back(v);
        }
        return ret;
        
    }
};
