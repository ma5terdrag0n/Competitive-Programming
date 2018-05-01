#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define inf 1000000007
#define fr first
#define sc second
#define eps 1e-15
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
bool isLower(char c){
	return (c <= 'z' and c >= 'a');
}
 

bool comp(string a, string b){
	return (a > b);
}

ll bs(vector<ll> &v, ll lo, ll hi, ll fin){
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(v[mid] == fin){
            return mid;
        }
        else if(v[mid] < fin){
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return -1;
}

void solve(){
    int n;
    scanf("%d", &n);
    int a[n], b[n], c[n], d[n];
    int A[n * n], B[n * n];
    for(int i = 0 ; i < n ; i ++){
        scanf("%d%d%d%d", a + i, b + i, c + i , d + i);
    }
    int m = 0;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ;j  ++){
            A[m++] = a[i] + b[j];
        }
    } 
    m = 0;
    for(int i = 0 ; i < n ;i ++){
        for(int j = 0 ; j < n ; j ++){
            B[m++] = -c[i] - d[j];
        }
    }
    sort(A, A + n * n);
    sort(B, B + n * n);
        int ca[n * n], cb[n * n];
    ca[0] = cb[0] = 1;
    int counter = 0;
    for(int i = 1 ; i < n * n ; i ++){
        if(A[i] == A[i-1]){
            ca[counter] ++;
        }else{
            ++counter;
            A[counter] = A[i];
            ca[counter] = 1;
        }
    }
    int counter2 = 0;
    for(int i = 1 ; i < n * n ; i ++){
        if(B[i] == B[i-1]){
            cb[counter2] ++;
        }else{
            ++counter2;
            B[counter2] = B[i];
            cb[counter2] = 1;
        }
    }
    ll ans = 0;
    for(int i = 0, j = 0 ; i <= counter && j <= counter2 ;){
        if(A[i] < B[j]){
            i ++;
        }else if(A[i] > B[j]){
            j ++;
        }else{
            ans += (ll)ca[i] * cb[j];
            ++i;
            ++j;
        }
    }
    printf("%lld\n",ans);
}
 
int main(){
	solve();
} 
