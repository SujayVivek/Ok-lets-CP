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
 
// const int MOD = 1e9 + 7;
 vector<int> palindromes;
 
// Function to check if a number is a palindrome
bool check(int n) {
    string s = to_string(n);
    int len = s.length();
    for(int i = 0; i < len / 2; i++) {
        if(s[i] != s[len - i - 1]) {
            return false;
        }
    }
    return true;
}
int calc(int sum, int latest, int n, vvi& dp, vi& palindromes) {
    if(sum == n) {
        return 1;
    }
    if(sum > n) return 0;
    if(dp[sum][latest] != -1) return dp[sum][latest];
 
    dp[sum][latest] = 0;
    for(int i = latest; i < palindromes.size(); i++) {
        int palindrome = palindromes[i];
        if(sum + palindrome <= n) {
            dp[sum][latest] = (dp[sum][latest] + calc(sum + palindrome, i, n, dp, palindromes)) % MOD;
        }
    }
    return dp[sum][latest];
}
 
void Solve() {
    int n;
    cin >> n;
    vvi dp(n+1, vi(n, -1));
    int result = calc(0, 0, n, dp, palindromes);
    cout << result % MOD << endl;
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
    for(int i = 1; i <= 1e4; i++) {
        if(check(i)) {
            palindromes.push_back(i);
        }
    }
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
 
    // auto end = chrono::high_resolution_clock::now();
    // auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}