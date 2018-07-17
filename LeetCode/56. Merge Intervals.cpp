/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool comp(Interval a, Interval b){
    if(a.start < b.start)return 1;
    else if(a.start > b.start)return 0;
    return (a.end < b.end);
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> v;
        int n = intervals.size();
        if(n==0)return v;
        if(n==1){
            return intervals;
        }
        Interval I = intervals[0];
        for(int i = 1; i < n ; i ++){
            if(I.end < intervals[i].start){
                v.push_back(I);
                I = intervals[i];
            }
            else if(I.end >= intervals[i].start){
                I.end = max(I.end, intervals[i].end);
            }
        }
        v.push_back(I);
        return v;
    }
};
