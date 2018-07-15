class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int len = 0;
        int pos[255];
        for(int i = 0 ; i < 255 ; i ++){
            pos[i] = -1;
        }
        for(int i = 0 ; i < s.size() ; i++){
            if(pos[s[i]] == -1){
                len++;
                ans = max(ans, len);
            }
            else{
                int x = pos[s[i]];
                if(i - len > x){
                    len++;
                    ans = max(ans, len);
                }else{
                    len = i - x;
                }
            }
            pos[s[i]] = i;
        }
        return ans;
        
    }
};
