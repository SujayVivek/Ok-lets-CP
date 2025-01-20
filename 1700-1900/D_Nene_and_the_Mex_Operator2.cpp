#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vector<pair<int,int>>op;
void OP(vector<int> &a, int l, int r)
{
    if (l == r)
    {
        if (a[l] != 0)
        {
            op.push_back({l, l});
            a[l] = 0;
        }
        return;
    }

    OP(a, l + 1, r);
    if (a[l] != r - l)
    {
        op.push_back({l, r});
        for (int i = l; i <= r; i++)
            a[i] = r - l;

        OP(a, l + 1, r);
    }
}

void calc(vector<int> &a, int l, int r)
{
    int s = 0;
    for (int i = l; i <= r; i++)
        s += a[i];

    if (s <= (r - l + 1) * (r - l + 1))
    {
        OP(a, l, r);
        op.push_back({l, r});
        for (int i = l; i <= r; i++)
        {
            a[i] = (r - l + 1);
        }
    }
    else
    {
        int mx = -1;
        int pos = -1;
        for (int i = l; i <= r; i++)
        {
            if (a[i] > mx)
            {
                mx = a[i];
                pos = i;
            }
        }

        if (pos != l)
            calc(a, l, pos - 1);

        if (pos != r)
            calc(a, pos + 1, r);
    }
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    calc(a, 0, n - 1);
    int s = 0;
    for (int i : a)
        s += i;

    cout << s << " " << op.size() << "\n";

    for (auto it : op)
        cout << it.first + 1 << " " << it.second + 1 << "\n";
}
