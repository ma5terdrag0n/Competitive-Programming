class Solution {
public:
    string convert(string s, int n) {
        if(s == "" || n == 1)return s;
        int a[s.size()];
        int p = 0;
        int flag = 1;
        for(int i = 0 ; i < s.size(); i++){
            a[i] = p;
            if(p == 0){
                flag = 1;       
            }
            if(p==n-1){
                flag=-1;
            }
            if(flag == 1)p++;
            else p--;
        }
        string ret = "";
        vector<char> v[n];
        for(int i = 0 ; i < s.size() ; i++){
            v[a[i]].push_back(s[i]);
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < v[i].size() ; j++){
                ret.push_back(v[i][j]);
            }
        }
        return ret;
    }
};
