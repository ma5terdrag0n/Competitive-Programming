class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == "" && t == "") return true;
        int counter = 0;
        for(int i = 0 ; i < t.size() ; i++){
            if(t[i] == s[counter]){
                counter++;
            }
            if(counter == s.size())return true;
        }
        return false;
    }
};
