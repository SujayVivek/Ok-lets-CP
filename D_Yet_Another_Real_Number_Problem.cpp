#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
typedef vector<ll> vll;

ll modular_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void Solve() {
    ll n;
    cin >> n;
    vll a(n, 0), pref(n, 0), pow_2(n, 0);
    
    cin >> a[0];
    ll p = __builtin_ctz(a[0]);
    pref[0] = a[0] / (1LL << p);  // Bit-shift to calculate a[i] / 2^p
    pow_2[0] = p;
    
    for (ll i = 1; i < n; i++) {
        cin >> a[i];
        p = __builtin_ctz(a[i]);
        ll b = a[i] / (1LL << p);
        pref[i] = (pref[i - 1] + b) % MOD;  // Accumulate without extra modulo here
        pow_2[i] = pow_2[i - 1] + p;
    }
    
    cout << a[0] << " ";
    for (int i = 1; i < n; i++) {
        ll power_mod = modular_pow(2LL, pow_2[i - 1], MOD);
        cout << (pref[i - 1] + (power_mod * a[i]) % MOD) % MOD << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        Solve();
    }
    return 0;
}
