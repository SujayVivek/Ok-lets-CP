#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
map<pair<int, int>, pair<int, int>> parent;

vector<pair<int, int>> path;

void pPath(pair<int, int> start, pair<int, int> end) {
    if (end == start) {
        path.push_back(start);
        return;
    }
    pPath(start, parent[end]);
    path.push_back(end);
}

bool check(int i, int j, vector<string> &grid) {
    return (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].length() && grid[i][j] != '#');
}

void bfs(pair<int, int> start, vector<string> &grid, vvi &dist) {
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
        auto pos = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = pos.first + dx[i], ny = pos.second + dy[i];
            if (check(nx, ny, grid) && dist[nx][ny] > 1 + dist[pos.first][pos.second]) {
                dist[nx][ny] = 1 + dist[pos.first][pos.second];
                parent[{nx, ny}] = pos;
                q.push({nx, ny});
            }
        }
    }
}

void Monsterbfs(vector<string> &grid, vvi &mdist, set<pair<int, int>> &monsters) {
    queue<pair<int, int>> q;
    for (auto it : monsters) {
        q.push(it);
        mdist[it.first][it.second] = 0;
    }

    while (!q.empty()) {
        auto pos = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = pos.first + dx[i], ny = pos.second + dy[i];
            if (check(nx, ny, grid) && mdist[nx][ny] > 1 + mdist[pos.first][pos.second]) {
                mdist[nx][ny] = 1 + mdist[pos.first][pos.second];
                q.push({nx, ny});
            }
        }
    }
}

void checkPrinter(vvi &dist, vvi &mdist, pair<int, int> start, int j, int i, vector<string> &grid) {
    if (grid[j][i]=='.' && dist[j][i] < mdist[j][i]) {
        cout << "YES" << endl;
        cout << dist[j][i] << endl;
        pPath(start, {j, i});
        for (int k = 0; k < path.size() - 1; k++) {
            if (path[k + 1].second > path[k].second) {
                cout << "R";
            } else if (path[k + 1].second < path[k].second) {
                cout << "L";
            } else if (path[k + 1].first < path[k].first) { 
                cout << "U";
            } else {
                cout << "D"; 
            }
        }
        cout << endl;
        exit(0);
    }
}

void Solve() {
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> monsters;
    pair<int, int> start;
    vector<string> grid;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
        for (int j = 0; j < m; j++) {
            if (s[j] == 'M')
                monsters.insert({i, j});
            else if (s[j] == 'A')
                start = {i, j};
        }
    }

    vvi dist(n, vi(m, 1e9)), mdist(n, vi(m, 1e9));
    bfs(start, grid, dist);
    Monsterbfs(grid, mdist, monsters);

    for (int i = 0; i < m; i++) checkPrinter(dist, mdist, start, 0, i, grid);  
    for (int i = 0; i < n; i++) checkPrinter(dist, mdist, start, i, m - 1, grid); 
    for (int i = 0; i < m; i++) checkPrinter(dist, mdist, start, n - 1, i, grid); 
    for (int i = 0; i < n; i++) checkPrinter(dist, mdist, start, i, 0, grid);  
    cout << "IMPOSSIBLE" << endl;
}

int32_t main() {
    int tt_ = 1;
    while (tt_--) {
        Solve();
    }
    return 0;
}
