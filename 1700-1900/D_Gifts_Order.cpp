#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 5;
const int INF = 1e18;

int a[MAXN];

struct Node {
    int max_val, min_val;
    int max_conv;  // Maximum convenience in this range
    
    Node() : max_val(-INF), min_val(INF), max_conv(-INF) {}
};

Node tree[4 * MAXN];

// Calculate convenience for a range
int get_convenience(int max_val, int min_val, int range_size) {
    return max_val - min_val - (range_size - 1);
}

Node combine(const Node &left, const Node &right, int left_size, int right_size) {
    Node res;
    // Get max and min values
    res.max_val = max(left.max_val, right.max_val);
    res.min_val = min(left.min_val, right.min_val);
    
    // Maximum convenience is maximum of:
    // 1. Left subtree's max convenience
    // 2. Right subtree's max convenience
    // 3. Convenience using entire range
    res.max_conv = max({
        left.max_conv,
        right.max_conv,
        get_convenience(res.max_val, res.min_val, left_size + right_size)
    });
    
    return res;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v].max_val = tree[v].min_val = a[tl];
        tree[v].max_conv = 0;  // Single element has convenience 0
        return;
    }
    
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    
    tree[v] = combine(tree[2 * v], tree[2 * v + 1], tm - tl + 1, tr - tm);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v].max_val = tree[v].min_val = new_val;
        tree[v].max_conv = 0;  // Single element
        a[pos] = new_val;
        return;
    }
    
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        update(2 * v, tl, tm, pos, new_val);
    else
        update(2 * v + 1, tm + 1, tr, pos, new_val);
    
    tree[v] = combine(tree[2 * v], tree[2 * v + 1], tm - tl + 1, tr - tm);
}

Node query(int v, int tl, int tr, int l, int r) {
    if (l > r) return Node();
    if (l == tl && r == tr)
        return tree[v];
    
    int tm = (tl + tr) / 2;
    if (r <= tm)
        return query(2 * v, tl, tm, l, r);
    if (l > tm)
        return query(2 * v + 1, tm + 1, tr, l, r);
        
    Node left = query(2 * v, tl, tm, l, tm);
    Node right = query(2 * v + 1, tm + 1, tr, tm + 1, r);
    return combine(left, right, tm - l + 1, r - tm);
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    build(1, 1, n);
    cout<<query(1,1,n,1,n).max_conv<<endl;
    while(q--) {
        int pos, val;
        cin >> pos >> val;
        update(1, 1, n, pos, val);
        cout << query(1, 1, n, 1, n).max_conv << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}