class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a.size() < b.size()){
            swap(a, b);
        }
        for(int i = b.size() ; i < a.size() ; i++){
            b.push_back('0');
        }
        int carry = 0;
        for(int i = 0 ; i < a.size() ; i ++){
            int ones = (a[i] == '1') + (b[i] == '1') + carry;
            if(ones == 1){
                s.push_back('1');
                carry = 0;
            }else if(ones == 2){
                s.push_back('0');
                carry = 1;
            }else if(ones == 3){
                s.push_back('1');
                carry = 1;
            }else{
                carry = 0;
                s.push_back('0');
            }
        }
        if(carry){
            s.push_back('1');
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
