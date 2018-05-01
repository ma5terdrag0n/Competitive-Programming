#include<bits/stdc++.h>
#define r(i,n) for(i=0;i<=n;i++)
using namespace std;
int main(){int t,a[100][100],i,j,n;cin>>t;while(t--){cin>>n;r(i,n-1){r(j,i)cin>>a[i][j];}for(i=n-2;i>=0;i--){r(j,i)a[i][j]+=max(a[i+1][j],a[i+1][j+1]);}cout<<a[0][0]<<endl;}}
