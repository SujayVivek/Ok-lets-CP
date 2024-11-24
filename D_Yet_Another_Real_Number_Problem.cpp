#include <bits/stdc++.h>
using namespace std;
#define Mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

// Modular multiplication to prevent overflow
int modMult(int a, int b, int mod) {
    return (a % mod * b % mod) % mod;
}

// Modular exponentiation for powers of two
int powerOfTwoModulo(int power, int mod) {
    int result = 1;
    int base = 2; // Base for powers of 2
    while (power > 0) {
        if (power % 2 == 1) {
            result = modMult(result, base, mod);
        }
        base = modMult(base, base, mod); // Square the base
        power /= 2;
    }
    return result;
}

void Solve() {
    int n;
    cin >> n;
    vi a(n, 0), b(n, 0), bPref(n, 0), cPref(n, 0), c(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int r = __builtin_ctz(a[i]);
        b[i] = a[i] / (1 << r);
        c[i] = r;
    }

    bPref[0] = b[0];
    cPref[0] = c[0];

    for (int i = 1; i < n; i++) {
        bPref[i] = bPref[i - 1] + b[i];
        cPref[i] = cPref[i - 1] + c[i];
    }

    vi ans(n, 0);
    ans[0] = a[0];
    int mx = 0, mxI = 0, mxEle = a[0];

    for (int i = 1; i < n; i++) {
        int shift = cPref[i] - cPref[mxI]; // Amount of shift
        if (modMult(a[i], powerOfTwoModulo(shift, Mod), Mod) >= mx || a[i] >= mxEle) {
            mx = modMult(a[i], powerOfTwoModulo(cPref[i - 1], Mod), Mod); // Replace bit-shift
            mxI = i;
            mxEle = max(mxEle, a[i]);
            ans[i] = (mx + bPref[i - 1]) % Mod;
        } else {
            ans[i] = max({
                ans[i - 1] + a[i],
                ans[mxI] + modMult(a[i], powerOfTwoModulo(cPref[i - 1] - cPref[mxI], Mod), Mod) + bPref[i - 1] - bPref[mxI],
                modMult(a[i], powerOfTwoModulo(cPref[i - 1], Mod), Mod) + bPref[i - 1]
            }) % Mod;
        }
    }

    for (auto &v : ans) {
        cout << v << " ";
    }
    cout << endl;
    return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
