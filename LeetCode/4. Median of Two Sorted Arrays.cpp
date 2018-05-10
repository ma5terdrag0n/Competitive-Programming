class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int foo, bar;
        foo = bar = 0;
        vector<int> sorted;
        while(foo < nums1.size() && bar < nums2.size()){
            if(nums1[foo] < nums2[bar]){
                sorted.push_back(nums1[foo++]);
            }else {
                sorted.push_back(nums2[bar++]);
            }
        }
        
        while(foo < nums1.size()){
            sorted.push_back(nums1[foo++]);
        }
        
        while(bar < nums2.size()){
            sorted.push_back(nums2[bar++]);
        }
        double median = 0;
        if(sorted.size()&1){
            return median = sorted[sorted.size()/2];
        }else{
            return median = (sorted[sorted.size()/2] + sorted[sorted.size()/2-1]) / 2.00;
        }
    }
};
