#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;
set<int> edge2;
set<int> edge1;

void bfs(int st) {
    queue<int> q;
    color[st] = 0;
    q.push(st);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    adj.resize(N + 1);
    color.resize(N + 1, -1);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        edge2.insert(u * 1000 + v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    int A = 0, B = 0;
    for (int i = 1; i <= N; ++i) {
        if (color[i] == 0) A++;
        else B++;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (color[i] != color[j]) {
                int code = i * 1000 + j;
                if (edge2.find(code) == edge2.end()) {
                    edge1.insert(code);
                }
            }
        }
    }
    int K = edge1.size();
    bool ok = false;
    if (K == 0) {
        cout << "Second" << endl;
    } else {
        if (K % 2 == 1) {
            cout << "First" << endl;
            ok = true;
        } else {
            cout << "Second" << endl;
        }
    }
    cout.flush();

    if (ok) {
        while (!edge1.empty()) {
            int code = *edge1.begin();
            int u = code / 1000;
            int v = code % 1000;
            cout << u << " " << v << endl;
            cout.flush();
            edge1.erase(code);
            int a, b;
            cin >> a >> b;
            if (a == -1 && b == -1) {
                return 0;
            }
            if (a > b) swap(a, b);
            code = a * 1000 + b;
            edge1.erase(code);
        }
    } else {
        while (true) {
            int a, b;
            cin >> a >> b;
            if (a == -1 && b == -1) {
                return 0;
            }
            if (a > b) swap(a, b);
            int code = a * 1000 + b;
            edge1.erase(code);
            if (!edge1.empty()) {
                code = *edge1.begin();
                int u = code / 1000;
                int v = code % 1000;
                cout << u << " " << v << endl;
                cout.flush();
                edge1.erase(code);
            }
        }
    }
    return 0;
}