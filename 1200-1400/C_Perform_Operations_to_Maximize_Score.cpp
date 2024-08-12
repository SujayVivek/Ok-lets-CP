#include <bits/stdc++.h>

using namespace std;

//   _______ _     _                     _        _        __             _   _            _                            
//  |__   __| |   (_)                   | |      (_)      / _|           | | | |          (_)                           
//     | |  | |__  _ ___    ___ ___   __| | ___   _ ___  | |_ ___  _ __  | |_| |__   ___   _ _ __  ___  __ _ _ __   ___ 
//     | |  | '_ \| / __|  / __/ _ \ / _` |/ _ \ | / __| |  _/ _ \| '__| | __| '_ \ / _ \ | | '_ \/ __|/ _` | '_ \ / _ \
//     | |  | | | | \__ \ | |_| (_) | |_| |  __/ | \__ \ | || (_) | |    | |_| | | |  __/ | | | | \__ \ |_| | | | |  __/
//     |_|  |_| |_|_|___/  \___\___/ \__,_|\___| |_|___/ |_| \___/|_|     \__|_| |_|\___| |_|_| |_|___/\__,_|_| |_|\___|

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
#define loopm(ii, i, n, p) for (ll ii = i; ii < n; ii+p)
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
    // Your code for each test case goes here
        int n, k; cin >> n >> k;
        vector <pair<int, int>> vpp(n);
        for (auto &x : vpp){
            cin >> x.ff;
        }
        for (auto &x : vpp){
            cin >> x.ss;
        }
        sort(all(vpp));
        ll ans = 0;
        loop(i,0,n){
            if (vpp[i].ss == 1){
                int med;
                if (i < n / 2) med = vpp[n / 2].ff;
                else med = vpp[(n - 2) / 2].ff;
                
                ans = max(ans, 0LL + vpp[i].ff + k + med);
            }
        } 
        int lo = 0, hi = 2e9;
        while (lo != hi){
            int mid = (1LL + lo + hi) / 2;
            int cnt = 0;
            vector <int> Bef;
            for (int i = 0; i < n - 1; i++){
                if (vpp[i].ff >= mid){
                    cnt++;
                } else if (vpp[i].ss == 1){
                    Bef.push_back(mid - vpp[i].ff); 
                }
            }
            reverse(all(Bef));
            int q = k;
            for (auto x : Bef) if (q >= x){
                q -= x;
                cnt++;
            } 
            if (cnt >= (n + 1) / 2) lo = mid;
            else hi = mid - 1;
        }
        ans = max(ans, 0LL + vpp[n - 1].ff + lo);
        cout << ans << "\n";
}
int32_t main() {
    auto begin = chrono::high_resolution_clock::now(); // Initialize the begin time measurement

    fastio();
    // #ifndef ONLINE_JUDGE
    //     freopen("error.txt", "w", stderr);
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