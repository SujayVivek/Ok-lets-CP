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
        int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<set<int>> vpq(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1) vpq[i] = vpq[i + 1];
        vpq[i].insert(v[i]);
    }

    vector<int> ans;
    int c = 0;
    int i = 0;
    map<int, int> mpp;

    while (i < n) {
        if (c % 2 == 0) {
            set<int> s = vpq[i];
            auto it = s.rbegin(); 
            while (it != s.rend() && mpp[*it] != 0) {
                ++it;
            }
            if (it == s.rend()) break;  
            int max_element = *it;
            while (i < n && v[i] != max_element) {
                i++;
            }
            if (i < n) {
                ans.push_back(v[i]);
                mpp[v[i]]++;
                c++;
                i++;
            }
        } else {
            set<int> s = vpq[i];
            auto it = s.begin(); 
            while (it != s.end() && mpp[*it] != 0) {
                ++it;
            }
            if (it == s.end()) break;

            int min_element = *it;
            while (i < n && v[i] != min_element) {
                i++;
            }
            if (i < n) {
                ans.push_back(v[i]);
                mpp[v[i]]++;
                c++;
                i++;
            }
        }
    }
    cout<<ans.size()<<endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
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