#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"


int FIND(int u, vi &parent)
{
    if (parent[u] != u)
    {
        parent[u] = FIND(parent[u], parent); 
    }
    return parent[u];
}

void MERGED(int u, int v, vi &parent, vi &rank)
{
    int rootU = FIND(u, parent);
    int rootV = FIND(v, parent);
    if (rootU != rootV)
    {
        if (rank[rootU] < rank[rootV])
            swap(rootU, rootV);
        parent[rootV] = rootU;
        if (rank[rootU] == rank[rootV])
            rank[rootU]++;
    }
}

void Solve()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<int, int>> edgesF(m1), edgesG(m2);
    for (int i = 0; i < m1; ++i)
    {
        int u, v;
        cin >> u >> v;
        edgesF[i] = make_pair(u, v);
    }


    for (int i = 0; i < m2; ++i)
    {
        int u, v;
        cin >> u >> v;
        edgesG[i] = make_pair(u, v);
    }

  
    vi parF(n + 1), rankF(n + 1, 0);
    vi parG(n + 1), rankG(n + 1, 0);


    for (int i = 1; i <= n; ++i)
    {
        parF[i] = i;
        parG[i] = i;
    }

    for (int i = 0; i < m2; ++i)
    {
        int u = edgesG[i].first;
        int v = edgesG[i].second;
        MERGED(u, v, parG, rankG);
    }


    int R_Edges = 0;
    for (int i = 0; i < m1; ++i)
    {
        int u = edgesF[i].first;
        int v = edgesF[i].second;
        if (FIND(u, parG) != FIND(v, parG))
        {
            R_Edges++; 
        }
        else
        {
            MERGED(u, v, parF, rankF); 
        }
    }
    map<int, set<int>> mpps;
    for (int i = 1; i <= n; ++i)
    {
        int rootG = FIND(i, parG);
        int rootF = FIND(i, parF);
        mpps[rootG].insert(rootF);
    }
    int A_Edges = 0;
    for (map<int, set<int>>::iterator it = mpps.begin(); it != mpps.end(); ++it)
    {
        A_Edges += (it->second.size() - 1);
    }
    cout << R_Edges + A_Edges << endl;
}

int32_t main()
{
    int tt_ = 1;
    cin >> tt_;
    while (tt_--)
    {
        Solve();
    }
    return 0;
}
