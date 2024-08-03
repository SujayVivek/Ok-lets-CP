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

void Solve() {
    // Input handling
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Vectors for storing positions of '*' and prefix sums
    vi hash(n, 0);
    vi ans;

    int sum = 0;

    // Calculating prefix sums and collecting '*' positions
    loop(i, 0, n) {
        if (s[i] == '*') {
            ans.pb(i);
        } else {
            sum += 1;
        }
        hash[i] = sum;
    }

    // Handling the case where there are no '*' characters
    if (ans.empty()) {
        cout << 0 << endl;
        return;
    }

    // Calculate minimum moves
    ll ct = 0;
    int r = ans.size();
    int q = ans[r / 2]; // Median position of '*'
    
    loop(i, 0, r) {
        ct += 1ll*abs(hash[ans[i]] - hash[q]);
    }

    // Output the result
    cout << ct << endl;
    return;
}

int32_t main() {
    auto begin = chrono::high_resolution_clock::now(); // Initialize the begin time measurement

    fastio();
    
    // Uncomment for local testing
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
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
