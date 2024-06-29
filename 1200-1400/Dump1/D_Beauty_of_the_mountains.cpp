#include <bits/stdc++.h>

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
#define loopm(ii, i, n, p) for (ll ii = i; ii < n; ii+=p)
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define MP make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;

ll counter(int i, int j, int k, vvll &hash) {
    ll ans = 0;
    if (i == 0 && j == 0) {
        ans = hash[i+k-1][j+k-1];
    } else if (i == 0) {
        ans = hash[i+k-1][j+k-1] - hash[i+k-1][j-1];
    } else if (j == 0) {
        ans = hash[i+k-1][j+k-1] - hash[i-1][j+k-1];
    } else {
        ans = hash[i+k-1][j+k-1] - hash[i-1][j+k-1] - hash[i+k-1][j-1] + hash[i-1][j-1];
    }
    return ans;
}
void printer(vvll &hash,int n, int m){
    loop(i,0,n){
        loop(j,0,m){
            cout<<hash[i][j]<<" ";
        }cout<<endl;
    }
}

void Solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int64_t diff = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        diff += (s[i][j] == '1' ? 1 : -1) * a[i][j];
      }
    }
    vector<vector<int>> f(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + (s[i - 1][j - 1] == '1' ? 1 : -1);
      }
    }
    int g = 0;
    for (int i = 0; i <= n - k; i++) {
      for (int j = 0; j <= m - k; j++) {
        int w = f[i + k][j + k] - f[i + k][j] - f[i][j + k] + f[i][j];
        g = __gcd(g, abs(w));
      }
    }
    if ((g == 0 && diff == 0) || (g > 0 && diff % g == 0)) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
    return;
  }



int32_t main() {
    auto begin = chrono::high_resolution_clock::now();

    fastio();
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }

    // auto end = chrono::high_resolution_clock::now();
    // auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
