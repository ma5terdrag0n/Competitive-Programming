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

ll fun(ll dist, ll *a, ll n) {
	ll k = 0;
	rep(n) {
		if(!i) continue;
		ll diff = a[i]-a[i-1];
		if(diff <= dist)continue;
		k += ceil(1.00*diff/dist) - 1;
	}
	return k;
}

void solve() {
	ll t;
	cin >> t;
	ll cas = 0;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		ll a[n];
		rep(n) {
			cin >> a[i];
		}

		ll hi = 0;
		ll lo = 1;
		rep(n){
			if(i) hi = max(hi, a[i] - a[i-1]);
		}
		ll ans = inf;
		while(lo <= hi) {
			ll mid = (lo + hi) / 2;
			ll foo = fun(mid, a, n);
			if(foo <= k) {
				ans = min(ans, mid);
				hi = mid-1;
			}else{
				lo = mid+1;
			}
		}

		cout << "Case #" << ++cas << ": " << ans << endl;
	}

}

int main(){
	std::ios::sync_with_stdio(0);
	solve();
	return 0;
}
