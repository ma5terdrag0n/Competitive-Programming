class Solution {
public:
    string s[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> ret;
    
    void allSubsequences(string n, int idx, string app){
        if(idx == n.size()){
            ret.push_back(app);
            return;
        }
        app.push_back('1');
        for(int i = 0 ; i < s[n[idx]-'0'].size() ; i++){
            app[idx] = s[n[idx]-'0'][i];
            allSubsequences(n, idx+1, app);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits == "")return ret;
        string ss = "";
        allSubsequences(digits, 0, ss);
        return ret;
    }
};
