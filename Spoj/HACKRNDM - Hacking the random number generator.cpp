#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<class c>
int binary_search(c *a, int lo, int hi, c key){
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(a[mid] == key){
            return mid;
        }else if(a[mid] < key){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return -1;
}
 

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n] = {0};
    for(int i = 0 ; i < n ; i ++){
        scanf("%d", a + i);
    }
    sort(a, a + n);
    int count = 0;
    for(int i = 0 ;i < n ; i ++){
        if(binary_search(a, 0, n-1, a[i] + k) != -1){
            count++;
        }
    }
    printf("%d", count);

}


int main(){
    freopen("input.in", "r" , stdin);
    int t = 1;
    // scanf("%d",&t);
    for(int ii = 0 ; ii < t ; ii ++){
        solve();
    }
}
