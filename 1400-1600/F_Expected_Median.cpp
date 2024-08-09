#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

// Function to compute x^y under modulo mod
ll power(ll x, ll y, ll mod) {
    ll result = 1;
    while (y > 0) {
        if (y % 2 == 1)
            result = (result * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return result;
}

// Function to precompute factorials and modular inverses
void precompute_factorials_and_inverses(vector<ll>& fact, vector<ll>& inv_fact, ll max_n, ll mod) {
    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= max_n; ++i) {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv_fact[max_n] = power(fact[max_n], mod - 2, mod);
    for (ll i = max_n - 1; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    }
}

// Function to compute nCr % mod
ll ncr(ll n, ll r, const vector<ll>& fact, const vector<ll>& inv_fact, ll mod) {
    if (r > n) return 0;
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

void Solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n, 0);
    ll s = 0;

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
        s %= mod;
    }
    
    ll z = (n - s + mod) % mod;

    vector<ll> fact(n + 1), inv_fact(n + 1);
    precompute_factorials_and_inverses(fact, inv_fact, n, mod);

    if (z == 0) {
        cout << ncr(n, k, fact, inv_fact, mod) << endl;
        return;
    }
    if (s <= k / 2) {
        cout << 0 << endl;
        return;
    }
    
    ll ans = 0;
    for (ll i = k / 2 + 1; i <= min(s + 1, k); ++i) {
        ll m = k - i;
        if (m <= z && i <= s) {
            ans = (ans + ncr(z, m, fact, inv_fact, mod) * ncr(s, i, fact, inv_fact, mod) % mod) % mod;
        }
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
