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
    set<pair<int, int>> edges;
    vector<int> deg(n + 1);
    for(int i = 0; i <  n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.insert(make_pair(a, b));
        edges.insert(make_pair(b, a));
        deg[a]++;
        deg[b]++;
    }
    int ans = 0;
    vector<pair<int, int>> b;
    for(int i = 0; i<n; i++)
    {
        b.push_back(make_pair(deg[i + 1], i + 1));
    }
    sort(b.begin(), b.end(), greater<pair<int, int>>());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (edges.find(make_pair(b[i].second, b[j].second)) == edges.end())
            {
                ans = max(ans, b[j].first + b[i].first - 1);
                break;
            }
        }
    }

    for (auto x : edges)
    {
        ans = max(ans, deg[x.first] + deg[x.second] - 2);
    }
    cout << ans << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}