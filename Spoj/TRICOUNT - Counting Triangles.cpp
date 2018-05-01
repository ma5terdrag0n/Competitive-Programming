// https://math.stackexchange.com/questions/203873/how-many-triangles
#include <iostream>
using namespace std;
typedef long long ll;
void solve(){
	int t;
	cin >> t;
	while(t--){
		  ll n;
		  scanf("%lld",&n);
          if(n%2)   
               printf("%lld\n",(((n)*(n+2)*(2*n+1)-1)/8));
          else
               printf("%lld\n",(((n)*(n+2)*(2*n+1))/8));
		
	}
}
int main() {
	// your code goes here
	solve();
	return 0;
}
