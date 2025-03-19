#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int N, X;
    cin >> N >> X;
    vector<int> U(N), D(N), S(N);
    int Sum = 0;
    int S_min = LLONG_MAX; 
    for (int i = 0; i < N; ++i) {
        cin >> U[i] >> D[i];
        S[i] = U[i] + D[i];
        Sum += S[i];
        if (S[i] < S_min) {
            S_min = S[i];
        }
    }
    int lo = 0, hi = S_min;
    int hmax = 0;
    auto check = [&](int H) {
        vector<pair<int, int>> vecs;
        for (int i = 0; i < N; ++i) {
            int a = max(0LL, H - D[i]);
            int b = min(U[i], H);
            if (a > b) return false;
            vecs.emplace_back(a, b);
        }
        int clo = vecs[0].first;
        int chi = vecs[0].second;
        for (int i = 1; i < N; ++i) {
            int a_i = vecs[i].first;
            int b_i = vecs[i].second;
            int nlo = max(a_i, clo - X);
            int nhi = min(b_i, chi + X);
            if (nlo > nhi) {
                return false;
            }
            clo = nlo;
            chi = nhi;
        }
        return true;
    };

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; 
        if (check(mid)) {
            hmax = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << Sum - N * hmax << endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}