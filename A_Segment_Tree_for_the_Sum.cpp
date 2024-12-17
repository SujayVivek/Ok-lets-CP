#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n, m; 
int arr[100001];
int SegTree[400001];

void build(int idx, int l, int r) {
    if(l == r) {
        SegTree[idx] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    SegTree[idx] = SegTree[2 * idx] + SegTree[2 * idx + 1];
}

void Upd(int idx, int l, int r, int pos, int val) {
    if(pos < l || pos > r) return;
    if(l == r) {
        SegTree[idx] = val;
        arr[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    Upd(2 * idx, l, mid, pos, val);
    Upd(2 * idx + 1, mid + 1, r, pos, val);
    SegTree[idx] = SegTree[2 * idx] + SegTree[2 * idx + 1];
}

int Query(int idx, int l, int r, int Lq, int Rq) {
    if(l > Rq || Lq > r) return 0;
    if(Lq <= l && r <= Rq) {
        return SegTree[idx];
    }
    int mid = (l + r) / 2;
    return Query(2 * idx, l, mid, Lq, Rq) + Query(2 * idx + 1, mid + 1, r, Lq, Rq);
}

void Solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n - 1);
    while(m--) {
        int a; cin >> a;
        if(a == 1) {
            int i, v; cin >> i >> v;
            Upd(1, 0, n - 1, i , v); // Adjust to 0-based index
        } else {
            int l, r; cin >> l >> r;
            int sum = Query(1, 0, n - 1, l, r - 1); // Adjust to 0-based index
            cout << sum << endl;
        }
    }
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
