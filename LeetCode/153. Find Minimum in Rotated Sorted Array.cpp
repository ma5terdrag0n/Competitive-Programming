class Solution {
public:
    int findMin(vector<int>& a) {
        int lo, hi;
        lo= 0;
        hi = a.size()-1;
        int n = a.size();
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(a[mid] > a[hi]){
                lo = mid+1;
            }else{
                hi = mid;
            }
        }
        return a[lo];
    }
};
