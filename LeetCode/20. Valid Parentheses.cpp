class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool ok = 1;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else{
                if(st.empty() || (st.top() != '(' and s[i] == ')') || (st.top() != '[' and s[i] == ']') || (st.top() != '{' and s[i] == '}')){
                    ok = 0;
                    break;
                }else{
                    st.pop();
                }
            }
        }
        if(ok and st.empty()){
            return 1;
        }
        return 0;
    }
};
