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
    int n;
        cin >> n;
        vi a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;
        int sum_a = accumulate(a.begin(), a.end(), 0LL);
        int sum_b = accumulate(b.begin(), b.end(), 0LL);
        if (sum_a < sum_b) {
            cout << -1 << "\n";
            return;
        }
        if (sum_a == sum_b) {
            vi A(a), B(b);
            sort(A.begin(), A.end()), sort(B.begin(), B.end());
            
            if (A == B) {
                int max_a = *max_element(a.begin(), a.end());
                int b_max = *max_element(b.begin(), b.end());
                int k = max(max_a, b_max) + 1;
                cout << k << "\n";
            } else {
                cout << -1 << "\n";
            }
            return;
        }
        int diff = sum_a - sum_b;
        int b_max = *max_element(b.begin(), b.end());
        vi div;
        for (int i = 1; i * i <= diff; ++i) {
            if (diff % i == 0) {
                div.push_back(i);
                if (i != diff / i) {
                    div.push_back(diff / i);
                }
            }
        }
        sort(div.begin(), div.end());
        vi candi;
        for (auto d : div) {
            if (d > b_max && d <= 1e9) {
                candi.push_back(d);
            }
        }
        sort(candi.begin(), candi.end());
        vi B(b);
        sort(B.begin(), B.end());
        bool found = false;
        for (auto k : candi) {
            vi mods;
            for (auto ai : a) {
                mods.push_back(ai % k);
            }
            sort(mods.begin(), mods.end());
            if (mods == B) {
                cout << k << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << -1 << "\n";
        }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}