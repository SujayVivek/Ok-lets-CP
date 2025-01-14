#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

const int maxn = 3e5 + 1;

vector<int> small_prime(maxn, 0);

void sieve()
{
    small_prime[1] = 1;
    for (int i = 2; i < maxn; ++i)
    {
        if (!small_prime[i])
        {
            small_prime[i] = i;
            for (int j = i * i; j < maxn; j += i)
            {
                if (!small_prime[j])
                    small_prime[j] = i;
            }
        }
    }
}

bool solve()
{
    int n, s, e;
    cin >> n;
    vector<int> v(n), dis(2 * maxn, -1), par(2 * maxn, -1);
    vector<vector<int>> g(2 * maxn);

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    cin >> s >> e;
    s--, e--;

    for (int i = 0; i < n; ++i)
    {
        while (small_prime[v[i]] > 1)
        {
            g[i].push_back(n + small_prime[v[i]]);
            g[n + small_prime[v[i]]].push_back(i);

            v[i] /= small_prime[v[i]];
        }
    }

    queue<int> q;
    q.push(s);
    dis[s] = 1;
    par[s] = -1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int child : g[curr])
        {
            if (dis[child] == -1)
            {
                par[child] = curr;
                dis[child] = dis[curr] + 1;
                q.push(child);
            }
        }
    }

    if (dis[e] == -1)
        return false;

    int node = e;
    vector<int> path;

    while (node != -1)
    {
        if (node < n)
            path.push_back(node);
        node = par[node];
    }

    reverse(path.begin(), path.end());

    cout << (dis[e] + 1) / 2 << endl;
    for (int node : path)
        cout << node + 1 << " ";

    return true;
}

int32_t main()
{
    int t = 1;
    sieve();
    while (t--)
    {
        if (solve())
        {
            // cout << "YES" << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}