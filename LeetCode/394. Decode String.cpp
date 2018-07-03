class Solution {
public:
    bool isnum(char c){
        return (c <= '9' and c >= '0');
    }
    
    string decodeString(string s) {
        string ret = "";
        for(int i = 0 ; i < s.size() ; i++){
            int freq = 0;
            string f = "";
            while(i < s.size() and !isnum(s[i])){
                ret.push_back(s[i]);
                i++;
            }
            while(i < s.size() and s[i] != '['){
                freq = freq*10 + (s[i] - '0');
                f.push_back(s[i]);
                i++;
            }
            i++;
            string x = "";
            stack<int> st;
            st.push(0);
            bool foo = 0;
            while(i < s.size() && !st.empty()){
                if(s[i] == ']'){
                    st.pop();
                }
                if(s[i] == '['){
                    st.push(0);
                }
                if(st.empty())break;
                if(s[i] == '[')foo = 1;
                x.push_back(s[i]);
                i++;
            }
            string g = x;
            if(foo){
                g = "";
                int front, last;
                for(int j = 0 ; j < x.size() ; j++){
                    if(isnum(x[j])){
                        front = j;
                        break;
                    }
                }
                for(int j = x.size() ; j >= 0 ; j --){
                    if(x[j] == ']'){
                        last = j;
                        break;
                    }
                }
                for(int j = front ; j <= last ; j++){
                    g.push_back(x[j]);
                }
                g = decodeString(g);
                string tmp = "";
                for(int j = 0 ; j < front ; j++)tmp.push_back(x[j]);
                tmp += g;
                for(int j = last + 1 ; j < x.size() ; j++){
                    tmp.push_back(x[j]);
                }
                g = tmp;
            }
            for(int j = 0 ; j < freq ; j ++){
                ret += g;
            }
        }
        return ret;
    }
};
