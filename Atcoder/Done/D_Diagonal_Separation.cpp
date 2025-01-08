#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve()
{   
    int n, m;
    cin >> n >> m;
    vvi v;
    for (int i = 1; i <= m; i++)
    {
        int dx, dy;
        char col;
        cin >> dx >> dy >> col;
        v.push_back({dx, dy, col == 'B'});
    }

    sort(v.begin(), v.end());
    int mn = n + 1;

    for (int i = 0; i < v.size(); i++)
    {
        int dx = v[i][0], dy = v[i][1], col = v[i][2];
        if ((col == 1) && (mn <= dy))
        {
            cout << "No";
            return;
        }
        if (!col)
            mn = min(mn, dy);
    }

    cout << "Yes";
    return;
}



int32_t main()
{
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--)
    {
        Solve();
    }
    return 0;
}
