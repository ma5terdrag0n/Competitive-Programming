#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sieve_size;
bitset <1000010> bs;
vector<ll> primes;
 
void sieve(ll upperbound){
  sieve_size=upperbound+1;
  bs.reset(),bs.flip();//set all nos. to 1
  bs.set(0,false);bs.set(1,false);//except 0 ans 1
  for(ll i=2;i<=sieve_size;i++){
    if(bs.test((size_t)i)){
      for(ll j=i*i;j<=sieve_size;j+=i){
        bs.set((size_t)j,false);
      }
      primes.push_back((ll)i);
    }
  }
}
 

int main() {
    sieve((ll) 1e6);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
        ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<primes[n-1]<<endl;
    }
    return 0;
}
