#include <bits/stdc++.h>

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
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

void solve_dp(vi &dp, int index, vi &ans, vi &hash, int x, vi &v) {
    if (index < 0) {
        if (accumulate(all(ans), 0) == x) {
            for (auto it : hash) {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    

    ans.push_back(v[index]); hash[index] = 1;
    solve_dp(dp, index - 2, ans, hash, x, v);
    ans.pop_back(); ans.push_back(-1 * v[index]); hash[index] = -1;
    solve_dp(dp, index - 2, ans, hash, x, v);
    ans.pop_back(); hash[index] = 0;
    solve_dp(dp, index - 1, ans, hash, x, v);
    return;
}

void Solve() {
    int x; cin >> x;
    int i = 1;
    vll v;
    v.push_back(0);
    if(x==1){
        cout<<1<<"\n"<<1<<endl;
        return;
    }
    
    while ((pow(2, i) - pow(2, i - 1)) <= x) {
        v.push_back(pow(2, i));
        i++;
    }

    int n = v.size();
    vector<int> nums(n);
    for (int j = 0; j < n; ++j) {
        nums[j] = 1 << j; // 2^j
    }
    cout<<n<<endl;
    vi hash(n, 0);
    vi ans;
    vi dp(n, -1);
    solve_dp(dp, n - 1, ans, hash, x, nums);
}

int32_t main() {
    auto begin = chrono::high_resolution_clock::now(); // Initialize the begin time measurement

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
