#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ispalindrome(int num){
   int pali=0;
    int counter=0;
    counter=num;
    while(counter){
        int rem=counter%10;
        pali=pali*10+rem;
        counter/=10;
    }
    if(pali==num)  return 1;
    else return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        int i,j,maxi=0,pax;
     
            for(i=101;i<999;i++){
                for(j=101;j<999;j++){
                    pax=i*j;
                    if(ispalindrome(pax)){
                        if(pax>maxi&&pax<num){
                            maxi=pax;
                        }
                    }
                }
            }
      
        cout<<maxi<<endl;
    }
    return 0;
}
