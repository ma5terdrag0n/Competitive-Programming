#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;

lli multiply(lli w[],lli b,lli size){
	lli i=size;
	lli temp=0;
	lli x=0,carry=0;
	for(x=0;x<i;x++){
		temp=w[x]*b+carry;
		w[x]=temp%10;
		carry=temp/10;
	}
	while(carry){
		w[x++]=carry%10;carry/=10;size++;
	}
	return size;
 
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    lli t;
    cin>>t;
    while(t--){
        lli num;
        cin >> num;
        lli s=0,su=1,w[60000],i=0,sum=0;
		    w[0]=1;
        for(s=1;s<=num;s++){
          su=multiply(w,2,su);
        }
        for(i=su-1;i>=0;i--) sum+=w[i];
        cout<<sum<<endl;
    }
    return 0;
}
