class Solution {
public:
    int countSubstrings(string s) {
        string tmp = "";
        for(int i= 0 ; i < s.size()-1; i ++){
            tmp.push_back(s[i]);
            tmp.push_back('|');
        }
        tmp.push_back(s[s.size()-1]);
        s = tmp;
        int ans = 0;
        for(int  i = 0 ; i < s.size() ; i ++){
            if(s[i] == '|'){
                int len = 0;
                int lo, hi;
                lo = i-1, hi = i+1;
                while(lo >= 0 && hi < s.size() && s[lo] == s[hi]){
                    
                    if(s[lo] != '|'){
                        len += 2;
                    }
                    lo--;
                    hi++;
                }
                ans += len/2;
            }else{
                int len = 1;
                int lo, hi;
                lo = i-1;
                hi = i+1;
                while(lo >= 0 && hi < s.size() && s[lo] == s[hi]){
                    if(s[lo] != '|')
                        len += 2;
                    lo--, hi++;
                }
                ans += len/2+1;
            }
                
        }
        return ans;
    }
};
