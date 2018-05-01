class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        string curr_prefix = strs[0];
        for(int i=1;i<strs.size();i++){
            string new_prefix="";
            for(int j=0;j<strs[i].size()&&j<curr_prefix.size();j++){
                if(strs[i][j] == curr_prefix[j]){
                    new_prefix.push_back(curr_prefix[j]);
                }else {
                    break;
                }
            }
            curr_prefix = new_prefix;
        }
        return curr_prefix;
    }
};
