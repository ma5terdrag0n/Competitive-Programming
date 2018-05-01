#include <iostream>
using namespace std;
int lcm(int num1,int num2){
	int	max=(num1>num2) ? num1 : num2; 
  while(1)                       
  {
      if(max%num1==0 && max%num2==0)
      {
          //printf("LCM of %d and %d is %d", num1, num2,max);
          return(max);
          break;          
      }
      ++max;
  }
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int num;cin>>num;
		int i,x=1;
		for(i=2;i<=num;i++){
			x=lcm(i,x);
		}
		cout<<x<<endl;
	}
	
	return 0;
}
