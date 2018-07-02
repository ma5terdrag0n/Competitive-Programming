class Solution {
public:
    int hammingDistance(int x, int y) {
        int p = x^y;
        int ans = 0;
        while(p > 0){
            if(p&1)ans++;
            p >>= 1;
        }
        return ans;
    }
};
