class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int i, j;
        i = j = 0;
        while(i <= j && i < a.size() && j < a.size()){
            while(j < a.size() && a[i] == a[j]){
                j++;
            }
            if(j != a.size()){
                swap(a[i+1], a[j]);
                i++;j++;
            }else{
                break;
            }
        }
        for(int k = a.size() - 1 ; k > i ; k--)a.pop_back();
        return a.size();
    }
};
