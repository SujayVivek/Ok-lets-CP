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
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<int> q(n);
    int mxI = find(p.begin(), p.end(), n) - p.begin();
    if (!(mxI & 1))
    {
        vector<pair<int, int>> v;
        for (int i = 1; i < n; i += 2)
            v.push_back({p[i], i});
        v.push_back({p[0], 0});
        for (int i = 2; i < n; i += 2)
            v.push_back({p[i], i});
        sort(v.begin(), v.begin() + (n / 2), greater<pair<int, int>>());
        sort(v.begin() + (n / 2) + 1, v.begin() + n, greater<pair<int, int>>());
        for (int i = 0; i < n; i++)
            q[v[i].second] = i + 1;
    }
    else 
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i += 2)
            v.push_back({p[i], i});
        v.push_back({p[n - 1], n - 1});
        for (int i = 1; i < n - 1; i += 2)
            v.push_back({p[i], i});
        sort(v.begin(), v.begin() + (n / 2), greater<pair<int, int>>());
        sort(v.begin() + (n / 2) + 1, v.begin() + n, greater<pair<int, int>>());
        for (int i = 0; i < n; i++)
            q[v[i].second] = i + 1;
    }
    for (int i = 0; i < n; i++)
        cout << q[i] << " \n"[i == n - 1];
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}