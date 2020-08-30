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

ll ans = 0;

class trieNode{
public:
	bool isLeaf;
	ll childCount, prefixLen;
	trieNode *child[27];

	trieNode(bool isLeaf = 0) {
		this->isLeaf = isLeaf;
		this->childCount = this->prefixLen = 0;
		rep(27) {
			this->child[i] = NULL;
		}
	}

};

void insert(trieNode *root, string s) {
	for(int i = 0 ; i < sz(s); i++) {
		int idx = s[i] - 'A';
		if(root->child[idx] == NULL) {
			root->child[idx] = new trieNode();
			root->child[idx]->prefixLen = root->prefixLen + 1;
		}
		root->child[idx]->childCount++;
		root = root->child[idx];
	}
	if(root->child[26]) root->child[26]->childCount++;
	else {
		root->child[26] = new trieNode(1);
		root->child[26]->prefixLen = root->prefixLen;
		root->child[26]->childCount++;
	}
}

void dfs(trieNode *root, ll k) {
	if(root->childCount < k) {
		return;
	}
	if(root->isLeaf and root->childCount == k) {
		ans += root->prefixLen;
		root->childCount = 0;
		return;
	}
	rep(27) {
		if(!root->child[i]) continue;
		root->childCount -= root->child[i]->childCount;
		if(root->child[i]->childCount >= k) {
			dfs(root->child[i], k);
		}
		root->childCount += root->child[i]->childCount;
	}	
	ans += (root->childCount / k) * root->prefixLen;
	root->childCount %= k;
}


void solve() {
	ll t;
	cin >> t;
	ll cas = 0;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		string s[n];
		trieNode *root = new trieNode();
		root->childCount = n;
		rep(n) {
			cin >> s[i];
			insert(root, s[i]);
		}
		ans = 0;
		dfs(root, k);
		cout << "Case #" << ++cas << ": " << ans << endl;
	}

}

int main(){
	std::ios::sync_with_stdio(0);
	solve();
	return 0;
}
