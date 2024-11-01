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
#define int long long
int modInverse(int a, int mod) {
    int m0 = mod, y = 0, x = 1;
    if (mod == 1) return 0;
    while (a > 1) {
        int q = a / mod;
        int t = mod;
        mod = a % mod, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}
void Solve() {
    int n, k;
    cin >> n >> k;
    vi a(n, 0);
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mpp[a[i]]++;
    }
    sort(a.rbegin(), a.rend()); 
    int chosen = a[0], c = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] == chosen) c++;
        else {
            chosen = a[i];
            c = 1;
        }
    }
    int m = mpp[chosen];
    int ans = 1;
    for (int i = 0; i < c; i++) {
        ans = ans * (m - i) % MOD;
        ans = ans * (modInverse(i + 1, MOD)) % MOD;  
    }

    cout << ans << endl;
}

// Function to compute modular inverse of a under modulo MOD


int32_t main() {
    int tt_;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}