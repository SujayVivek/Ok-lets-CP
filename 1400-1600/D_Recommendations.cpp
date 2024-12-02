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
    vvi v(n, vi(3, 0)); 
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l *= 2, r *= 2;
        int mid = (l + r) / 2;
        int dif = mid - l;
        v[i] = {mid, dif, i};
    }
    sort(v.begin(), v.end());
    vi fin_ans(n, 0);
    for (int i = 0; i < n; i++) {
        int a = i - 1, b = i + 1;
        int LL = -1, LR = -1, RL = -1, RR = -1;
        while ((a >= 0 && LL == -1) || (b < n && RR == -1)) {
            if (a >= 0 && LL == -1) {
                if (v[a][0] + v[a][1] > v[i][0] + v[i][1] && v[a][0] < v[i][0] - v[i][1]) {
                    LL = v[a][0], LR = v[a][0] + v[a][1];
                }
                a--;
            }
            if (b < n && RR == -1) {
                if (v[b][0] - v[b][1] < v[i][0] - v[i][1] && v[b][0] > v[i][0] + v[i][1]) {
                    RR = v[b][0], RL = v[b][0] - v[b][1];
                }
                b++;
            }
        }
        if (LL != -1 && RR != -1) {
            int left = max(LL, RL);
            int right = min(RR, LR);
            fin_ans[v[i][2]] =  (right - left) - 2 * v[i][1];
        }
        else{
            fin_ans[v[i][2]] = 0;
        }
    }
    for (auto &x : fin_ans) {
        cout << x/2 << endl;
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