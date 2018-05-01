#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define inf 1000000007
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool isLower(char c){
	return (c <= 'z' and c >= 'a');
}


ll dp[11111] = {0};

void preprocess(){
	memset(dp, inf, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 1 ; i <= 100 ; i ++){
		dp[i*i] = 1;
	}
	for(int i = 3 ; i < 10001 ; i ++){
		for(int j = 1 ; j < i ; j ++){
			dp[i] = min(dp[i], dp[i-j] + dp[j]);
		}
	}
}

ll solve(){
	ll n;
	cin >> n;
	return dp[n];
}


int main(){
	// int start = clock();
	freopen("input.in" , "r" , stdin);
	freopen("output.txt", "w", stdout);
	ll t;
	cin >> t;
	preprocess();
	for(int i = 0 ; i < t ; i ++){
		cout << "Case #" << i + 1 << ": " << solve() << endl;
	}
	// cout << n;
	// int stop = clock();
	// cout << (stop - start) / 1000.0000<< endl;
}
