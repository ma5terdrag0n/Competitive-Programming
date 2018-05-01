#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll bin(ll n){
	ll ret=0;
	while(n){
		ret = ret*10 + n%2;
		n/=2;
	}
	return ret;
}

ll digits(ll n){
	ll ret=0;
	while(n){
		ret++;
		n>>=1;
	}
	return ret;
}

void fun(ll n){
	if(n==2){
		cout<<2;
		return ;
	}
	ll c = bin(n);
	ll i = digits(n)-1;

	if(c==1){
		if(i==0)
			cout<<"2("<<i<<")";
		else {
			cout<<"2(";fun(i);cout<<")";
		}
	}else {
		while(c){
			if(c%10 == 1){
				fun(pow(2,i));
				if(c/10){
					cout<<"+";
				}
			}
			i--; 
			c/=10;
		}
	}
}

int main(){
	ll a[7] = {137, 1315, 73, 136, 255, 1384, 16385};
	for(int i=0;i<7;i++){
		cout<<a[i]<<"=";
		fun(a[i]);
		cout<<endl;
	}
}
