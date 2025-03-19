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
    vi a(n);
    map<int, vector<int>> mpset;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mpset[a[i]].push_back(i);
    }
    int minDist = 1e18;
    for (auto &it : mpset) {
        for (int i = 1; i < it.second.size(); i++) {
            minDist = min(minDist, abs(it.second[i] - it.second[i - 1] + 1));
        }
    }
    cout << (minDist==1e18?-1:minDist) << endl;
}

int32_t main() {
    int tt_ = 1;
    while (tt_--) {
        Solve();
    }
    return 0;
}
