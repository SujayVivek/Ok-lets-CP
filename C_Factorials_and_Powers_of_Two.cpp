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
// set<int>pow;

ll calc(ll sum, ll latest, vvll &dp, vll &v) {
    if (sum < 0) {
        return LLONG_MAX; 
    } else if (sum == 0) {
        return 0; 
    }
    
    if (dp[sum][latest] != -1) return dp[sum][latest];  
    
    dp[sum][latest] = LLONG_MAX; // Initialize to a large value
    for (ll i = latest + 1; i < v.size(); i++) {
        ll result = calc(sum - v[i], i, dp, v);
        if (result != LLONG_MAX){
            dp[sum][latest] = min(dp[sum][latest], 1 + result);
        }
    }
    return dp[sum][latest];
}

void Solve(vll &v) {
    ll n;
    cin >> n;
    vvll dp(n + 1, vll(v.size(), -1));  // Resize dp for n+1 sums and v.size() elements
    ll result = calc(n, 0, dp, v);
    
    if (result == LLONG_MAX) {    
        cout << n<<endl;
    } else {
        cout << result << "\n";
    }
}

int32_t main() {
    auto begin = chrono::high_resolution_clock::now();  // Initialize the begin time measurement

    int tt_ = 1;
    cin >> tt_;
    ll f = 1;
    map<ll, int> mp;
    vll v;
    
    loop(i, 1, 16) {
        f = f * i;
        mp[f]++;
        v.push_back(f);
    }
    
    f = 2;
    long long q = 1e12;
    while (q) {
        if (!mp[f]) {
            v.push_back(f);
        }
        f *= 2;
        q /= 2;
    }
    
    sort(v.begin(), v.end());
    
    while (tt_--) {
        Solve(v);
    }

    return 0;
}