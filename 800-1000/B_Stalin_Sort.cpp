#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
#define endl "\n"
#define pb push_back
#define MP make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    map<int, int> mpp;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mpp[a[i]]++;
    }

    vector<int> sort_a = a;
    sort(sort_a.begin(), sort_a.end());

    int ans = 1e9;

    for (int i = 0; i < n; i++) {
        int dist = upper_bound(sort_a.begin(), sort_a.end(), a[i]) - sort_a.begin();
        int nums_above = sort_a.size() - dist;
        // cout<<nums_above<<"HI"<<endl;
        ans = min(ans, i + 1 + nums_above);
        auto it = lower_bound(sort_a.begin(), sort_a.end(), a[i]);
        if (it != sort_a.end()) {
            sort_a.erase(it);
        }
    }
    cout << ans-1 << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}