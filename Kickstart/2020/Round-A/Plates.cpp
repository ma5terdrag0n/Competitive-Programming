#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unordered_map>
#include <assert.h>

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define sz(x) x.size()
#define rep(n) for (ll i = 0; i < n; i++)
#define repc(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define DEC(i, x, y) for (int i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a + n

using namespace std;

// Some typedef's
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const ll inf = 1e18;
const double enf = 1e-12;
//--------------

const int N = 50, K = 30;

ll a[N][K];
ll n, k;
ll dp[N][N*K];

ll rec(ll row, ll p) {
	if(p <= 0) return 0;
	ll rows = n - row;
	ll cols = k;
	if(rows*cols < p) return 0;
	ll ans = 0;
	if(row == n-1) {
		return a[row][p-1];
	}
	rep(k+1) {
		if(i > p) break;
		ll sum = 0;
		if(i) {
			sum += a[row][i-1];
		}

		ll foo = dp[row+1][p-i] == -1 ? rec(row+1, p - i) : dp[row+1][p-i];

		ans = max(ans, sum + foo);
	}
	return dp[row][p] = ans;
}

void solve() {
	ll t;
	cin >> t;
	ll cas = 0;
	while(t--) {
		ll p;
		cin >> n >> k >> p;
		rep(n) {
			repc(j, k) {
				cin >> a[i][j];
				if(j) {
					a[i][j] += a[i][j-1];
				}
			}
		}

		rep(n) {
			repc(j, n*k){
				dp[i][j] = -1;
			}
		}

		cout << "Case #" << ++cas << ": " << rec(0, p) << endl;
	}

}

int main(){
	std::ios::sync_with_stdio(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#else
	// online submission
	#endif
	solve();
	return 0;
}
