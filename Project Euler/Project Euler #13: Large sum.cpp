#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    int a[t][50];
    int j=0,i=0;
    string num;
    for(i=0;i<t;i++){
        cin>>num;
        
        for(j=0;j<50;j++){
            a[i][j]=((int)num[49-j]-48);
        }
    }
    int f=0;
    int c[60],sum=0,carry=0;
    for(j=0;j<50;j++){
        for(i=0;i<t;i++){
            sum+=a[i][j];
        }
         sum+=carry;
         carry=sum/10;
         c[f++]=sum%10;
         sum=0;
    }
    c[f]=carry;
    if(carry!=0){
      int se=carry;
      while(se>0){
    	  c[f++]=se%10;
    	  se/=10;
      }
    }
    
    for(i=f-1;i>f-11;i--){
        	cout<<c[i];
    }
    
    return 0;
}
