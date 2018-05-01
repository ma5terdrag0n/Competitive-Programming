class Solution {
public:
    bool isPalindrome(int num) {
        int temp=num,ans=0;
        if(num<0) return false;
        while(num!=0){
            ans=ans*10+num%10;
            num/=10;
        }
        if(ans==temp) return true;
        else return false;
    }
};
