#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n, m;
vector<string> grid;
vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void Solve() {
    cin >> n >> m;
    grid.resize(n);
    for (auto &s : grid) cin >> s;

    pair<int, int> start = {-1, -1}, finish = {-1, -1};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') start = {i, j};
            if (grid[i][j] == 'T') finish = {i, j};
        }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(16, 1e9)));

    queue<tuple<int, int, int, int>> que;
    for (int k = 0; k < 4; k++) {
        dp[start.first][start.second][k * 4 + 1] = 0;
        que.emplace(start.first, start.second, k, 1);
    }

    while (!que.empty()) {
        auto Top = que.front();
        int i = get<0>(Top);
        int j = get<1>(Top);
        int last_d = get<2>(Top);
        int steps = get<3>(Top);
        que.pop();
        int cur_d = dp[i][j][last_d * 4 + steps];
        for (int d = 0; d < 4; d++) {
            int x = i + directions[d].first;
            int y = j + directions[d].second;
            
            if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#') continue;

            int nsteps = (d == last_d ? steps + 1 : 1);
            if (nsteps >= 4 || dp[x][y][d * 4 + nsteps] <= cur_d + 1) continue;

            dp[x][y][d * 4 + nsteps] = cur_d + 1;
            que.emplace(x, y, d, nsteps);
        }
    }

    int ans = 1e9;
    for (int k = 0; k < 4; k++) {
        for (int s = 1; s <= 3; s++) {
            ans = min(ans, dp[finish.first][finish.second][k * 4 + s]);
        }
    }

    cout << (ans == 1e9 ? -1 : ans) << endl;
}

int32_t main() {
    int tt_ = 1;
    while (tt_--) {
        Solve();
    }
    return 0;
}
