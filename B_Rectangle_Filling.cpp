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
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    set<int> B, W; 
    for(int i = 0; i<n; i++){
        if(grid[i][0] == 'W') W.insert(1);
        else B.insert(1);

        if(grid[i][m-1]=='W')W.insert(2);
        else B.insert(2);
    }
    for(int i = 0; i<m; i++){
        if(grid[0][i] == 'W')W.insert(3);
        else B.insert(3);

        if(grid[n-1][i]=='W')W.insert(4);
        else B.insert(4);
    }
    if(W.size() == 4 || B.size() == 4){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
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