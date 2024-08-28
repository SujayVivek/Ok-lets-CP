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
    string s;
    cin >> s;
    map<char, int> mpp;
    loop(i, 0, n) {
        mpp[s[i]]++;
    }
    vvi v;
    for (auto it : mpp) {
        v.push_back({it.second, it.first - 'a'});
    }
    sort(all(v), greater<vi>());
    int i = 0, j = 1;
    if (v.size() == 1) {
        cout << s << endl;
        return;
    }
    string ans = "";
    int c = 0;
    while (i < v.size() && j < v.size()) {
        if (c % 2 == 0) {
            ans += (char)(v[i][1] + 'a');
            v[i][0]--;
        } else {
            ans += (char)(v[j][1] + 'a');
            v[j][0]--;
        }
        c++;

        if (v[i][0] == 0) {
            i = j;
            j++;
            c = 0;
        }

        if (j < v.size() && v[j][0] == 0) {
            j++;
            c = 0;
        }
    }
    if (i < v.size()) {
        for (int q = i; q < v.size(); q++) {
            while (v[q][0] > 0) {
                ans += (char)(v[q][1] + 'a');
                v[q][0]--;
            }
        }
    }

    cout << ans << endl;
    return;
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