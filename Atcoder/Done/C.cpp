#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int H, W, D;
vector<vector<char>> grid;
vector<vector<bool>> visited;

void dfs(int x, int y, int remaining_distance) {
    if (remaining_distance < 0 || x < 0 || y < 0 || x >= H || y >= W) return; 
    if (grid[x][y] == '#' || visited[x][y]) return; 

    visited[x][y] = true; 

    dfs(x + 1, y, remaining_distance - 1); // Down
    dfs(x - 1, y, remaining_distance - 1); // Up
    dfs(x, y + 1, remaining_distance - 1); // Right
    dfs(x, y - 1, remaining_distance - 1); // Left
}

void Solve() {
    cin >> H >> W >> D;

    grid.assign(H, vector<char>(W));
    visited.assign(H, vector<bool>(W, false));

    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

 
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'H' && !visited[i][j]) {
                dfs(i, j, D); 
            }
        }
    }

    int count = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (visited[i][j] && grid[i][j] != '#') {
                count++;
            }
        }
    }

    cout << count << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solve();
    return 0;
}
