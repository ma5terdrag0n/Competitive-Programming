/*
Simple Logic but it took time to solve it!
F. Greedy
   Complete the baisc rectangle first by finding top left and bottom right ith character (A-Z)
   Now we are left with only '?'
   Expand all rectangles towards right first.
   Then expand all rectangles towards left.
   Then expand all rectangles upwards.
   Finally expand all rectangles downwards.
*/

#include <bits/stdc++.h>
#include <cstdio>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define sz(x) x.size()
#define rep(n) for (int i = 0; i < n; i++)
#define repc(i, n) for (int i = 0; i < n; i++)
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

//------------------------------------------------------------------------

class codeJam
{
public:
  ll t;
  ll currCase;
  codeJam(ll test) : t(test), currCase(1)
  {
    while (t--)
      process();
  }
  void process();
  inline void printCaseN()
  {
    std::cout << "Case #" << currCase << ":\n";
    ++currCase;
  }

  inline void printCaseA()
  {
    std::cout << "Case #" << currCase << " ";
    ++currCase;
  }
};

void codeJam::process()
{
  {
    printCaseN();
    ll n, m;
    cin >> n >> m;
    char a[n][m];
    vii v[26];
    rep(n)
    {
      repc(j, m)
      {
        cin >> a[i][j];
        if (a[i][j] != '?')
        {
          v[a[i][j] - 'A'].pb({i, j});
        }
      }
    }

    ii dim[26] = {{0, 0}};

    for (int i = 0; i < 26; i++)
    {
      if (v[i].size())
      {
        ll toplefti, topleftj, bottomrighti, bottomrightj;
        toplefti = bottomrighti = v[i][0].fr;
        topleftj = bottomrightj = v[i][0].sc;
        for (int j = 1; j < v[i].size(); j++)
        {
          toplefti = min(v[i][j].fr, toplefti);
          topleftj = min(v[i][j].sc, topleftj);
          bottomrighti = max(v[i][j].fr, bottomrighti);
          bottomrightj = max(v[i][j].sc, bottomrightj);
        }
        for (int j = toplefti; j <= bottomrighti; j++)
        {
          for (int k = topleftj; k <= bottomrightj; k++)
          {
            a[j][k] = i + 'A';

            v[i].pb({j, k});
          }
        }
        dim[i] = {bottomrighti - toplefti + 1, bottomrightj - topleftj + 1};
        // expanding right
        for (int k = bottomrightj + 1; k < m; k++)
        {
          bool ok = 1;
          for (int j = toplefti; j <= bottomrighti; j++)
          {
            if (a[j][k] != '?')
            {
              ok = 0;
              break;
            }
          }
          if (!ok)
            break;
          bottomrightj++;
          for (int j = toplefti; j <= bottomrighti; j++)
          {
            a[j][k] = i + 'A';

            v[i].pb({j, k});
          }
        }
      }
    }

    for (int i = 0; i < 26; i++)
    {
      if (v[i].size())
      {
        ll toplefti, topleftj, bottomrighti, bottomrightj;
        toplefti = bottomrighti = v[i][0].fr;
        topleftj = bottomrightj = v[i][0].sc;
        for (int j = 1; j < v[i].size(); j++)
        {
          toplefti = min(v[i][j].fr, toplefti);
          topleftj = min(v[i][j].sc, topleftj);
          bottomrighti = max(v[i][j].fr, bottomrighti);
          bottomrightj = max(v[i][j].sc, bottomrightj);
        }
        for (int j = toplefti; j <= bottomrighti; j++)
        {
          for (int k = topleftj; k <= bottomrightj; k++)
          {
            a[j][k] = i + 'A';
            v[i].pb({j, k});
          }
        }
        dim[i] = {bottomrighti - toplefti + 1, bottomrightj - topleftj + 1};

        // expanding left
        for (int k = topleftj - 1; k >= 0; k--)
        {
          bool ok = 1;
          for (int j = toplefti; j <= bottomrighti; j++)
          {
            if (a[j][k] != '?')
            {
              ok = 0;
              break;
            }
          }
          if (!ok)
            break;
          topleftj--;
          for (int j = toplefti; j <= bottomrighti; j++)
          {
            a[j][k] = i + 'A';

            v[i].pb({j, k});
          }
        }
      }
    }

    for (int i = 0; i < 26; i++)
    {
      if (v[i].size())
      {
        ll toplefti, topleftj, bottomrighti, bottomrightj;
        toplefti = bottomrighti = v[i][0].fr;
        topleftj = bottomrightj = v[i][0].sc;
        for (int j = 1; j < v[i].size(); j++)
        {
          toplefti = min(v[i][j].fr, toplefti);
          topleftj = min(v[i][j].sc, topleftj);
          bottomrighti = max(v[i][j].fr, bottomrighti);
          bottomrightj = max(v[i][j].sc, bottomrightj);
        }
        for (int j = toplefti; j <= bottomrighti; j++)
        {
          for (int k = topleftj; k <= bottomrightj; k++)
          {
            a[j][k] = i + 'A';

            v[i].pb({j, k});
          }
        }
        dim[i] = {bottomrighti - toplefti + 1, bottomrightj - topleftj + 1};

        // expanding top
        for (int j = toplefti - 1; j >= 0; j--)
        {
          bool ok = 1;
          for (int k = topleftj; k <= bottomrightj; k++)
          {

            if (a[j][k] != '?')
            {
              ok = 0;
              break;
            }
          }
          if (!ok)
            break;
          toplefti--;
          for (int k = topleftj; k <= bottomrightj; k++)
          {
            a[j][k] = i + 'A';

            v[i].pb({j, k});
          }
        }
      }
    }

    for (int i = 0; i < 26; i++)
    {
      if (v[i].size())
      {
        ll toplefti, topleftj, bottomrighti, bottomrightj;
        toplefti = bottomrighti = v[i][0].fr;
        topleftj = bottomrightj = v[i][0].sc;
        for (int j = 1; j < v[i].size(); j++)
        {
          toplefti = min(v[i][j].fr, toplefti);
          topleftj = min(v[i][j].sc, topleftj);
          bottomrighti = max(v[i][j].fr, bottomrighti);
          bottomrightj = max(v[i][j].sc, bottomrightj);
        }
        for (int j = toplefti; j <= bottomrighti; j++)
        {
          for (int k = topleftj; k <= bottomrightj; k++)
          {
            a[j][k] = i + 'A';

            v[i].pb({j, k});
          }
        }
        dim[i] = {bottomrighti - toplefti + 1, bottomrightj - topleftj + 1};
        // expanding bottom
        for (int j = bottomrighti + 1; j < n; j++)
        {
          bool ok = 1;
          // cout << i << " " << j << "  " << topleftj << " " << bottomrightj << endl;
          for (int k = topleftj; k <= bottomrightj; k++)
          {
            if (a[j][k] != '?')
            {
              ok = 0;
              break;
            }
          }
          // cout << ok << endl;
          if (!ok)
            break;
          bottomrighti++;
          for (int k = topleftj; k <= bottomrightj; k++)
          {
            a[j][k] = i + 'A';

            v[i].pb({j, k});
          }
        }
      }
    }


    rep(n)
    {
      repc(j, m)
      {
        cout << a[i][j];
      }
      cout << endl;
    }
  }
}

void solve()
{
  ll t;
  cin >> t;
  codeJam cj(t);
}

int main()
{
  std::ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef ONLINE_JUDGE
#else
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ll t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
}
