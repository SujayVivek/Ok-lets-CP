#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
#define endl "\n"
#define pb push_back
#define MP make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
// int n;
int n;
vector<vector<char>> grid;
vector<vector<ll>> dp;

bool check(int i, int j) {
    if (grid[i][j] == '*') return false;
    return true;
}

int calc(int i, int j) {
    if (i == n - 1 && j == n - 1) {
        return grid[i][j] == '*' ? 0 : 1; 
    }

    if (dp[i][j] != -1) return dp[i][j];  
    dp[i][j] = 0;  
    if (i + 1 < n && check(i + 1, j)) dp[i][j] = (dp[i][j]+calc(i + 1, j))%MOD;

    
    if (j + 1 < n && check(i, j + 1)) dp[i][j] = (dp[i][j] + calc(i, j + 1))%MOD;

    return dp[i][j];
}

void Solve() {
    cin >> n;
    grid = vector<vector<char>>(n, vector<char>(n));
    dp = vector<vector<ll>>(n, vector<ll>(n, -1)); 


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    if(grid[0][0]=='*') {
        cout<<0<<endl;return;
    }
    int result = calc(0, 0);
    cout << result%MOD << endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}