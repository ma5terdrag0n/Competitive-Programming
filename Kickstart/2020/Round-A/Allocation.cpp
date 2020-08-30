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


bool poss(double mid, ll *a, ll n, ll d) {
	double t = 1.00*a[0] + mid;
	// cout << mid << endl;
	rep(n) {
		// cout << t << " ";
		if(!i) continue;
		if(double(a[i] + d) < t) return 0;
		t = t + mid;
		if(i+1 < n){
			t = max(t, double(a[i+1]));
		}
	}
	return 1;
}

void solve() {
	ll t;
	ll cas = 0;
	cin >> t;
	while(t--) {
		ll n,b;
		cin >> n >> b;
		ll a[n];
		rep(n) {
			cin >> a[i];
		}
        sort(a,a + n);
		ll ans = 0;
		ll cost = 0;
		rep(n) {
			if(cost + a[i] > b) break;
			cost += a[i];
			ans ++; 

		}
		cout << "Case #" << ++cas << ": ";
		cout << ans << endl;
	}
}

int main(){
	solve();
	return 0;
}
