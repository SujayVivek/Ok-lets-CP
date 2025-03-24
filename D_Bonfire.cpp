#include <bits/stdc++.h>
using namespace std;
#define int long long

struct ph {
    size_t operator()(const pair<int,int> &p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) + 0x9e3779b9 + (hash<int>()(p.first) << 6) + (hash<int>()(p.first) >> 2));
    }
};

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, r, c;
    cin >> n >> r >> c;
    string s, a(n, '0');
    cin >> s;
    
    unordered_set<pair<int,int>, ph> vis;
    pair<int,int> cur = {0,0};
    vis.insert(cur);
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'N') cur.first--;
        else if (s[i] == 'S') cur.first++;
        else if (s[i] == 'E') cur.second++;
        else cur.second--;
        
        vis.insert(cur);
        if (vis.count({cur.first - r, cur.second - c})) a[i] = '1';
    }
    
    cout << a << "\n";
    return 0;
}