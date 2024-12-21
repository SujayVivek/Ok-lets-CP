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
vector<pair<int,int>> SegTree(400001);


void build(int idx, int l, int r) {
    if(l == r) {
        SegTree[idx] = {arr[l], 1};
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    if(SegTree[2*idx].first == SegTree[2*idx + 1].first){
        SegTree[idx] = {SegTree[2*idx].first, SegTree[2*idx].second + SegTree[2*idx + 1].second};
    }else{
        if(SegTree[2*idx].first> SegTree[2*idx + 1].first){
            SegTree[idx] = SegTree[2*idx + 1];
        }else{
            SegTree[idx] = SegTree[2*idx];
        }
    }
}

void Upd(int idx, int l, int r, int pos, int val) {
    if(pos < l || pos > r) return;
    if(l == r) {
        SegTree[idx].first = val;
        arr[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    Upd(2 * idx, l, mid, pos, val);
    Upd(2 * idx + 1, mid + 1, r, pos, val);
    if(SegTree[2*idx].first == SegTree[2*idx + 1].first){
        SegTree[idx] = {SegTree[2*idx].first, SegTree[2*idx].second + SegTree[2*idx + 1].second};
    }else{
        if(SegTree[2*idx].first> SegTree[2*idx + 1].first){
            SegTree[idx] = SegTree[2*idx + 1];
        }else{
            SegTree[idx] = SegTree[2*idx];
        }
    }
}

pair<int,int> Query(int idx, int l, int r, int Lq, int Rq) {
    if(l > Rq || Lq > r) return {1e9, 0};
    if(Lq <= l && r <= Rq) {
        return SegTree[idx];
    }
    int mid = (l + r) / 2;
    // return min(Query(2 * idx, l, mid, Lq, Rq), Query(2 * idx + 1, mid + 1, r, Lq, Rq));
    pair<int,int> A = Query(2*idx, l, mid, Lq, Rq), B = Query(2*idx + 1, mid + 1, r, Lq, Rq);
    if(A.first == B.first){
        return {A.first, A.second + B.second};
    }else{
        if(A.first > B.first){
            return  B;
        }else{
            return A;
        }
    }
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
            pair<int,int> MIN = Query(1, 0, n - 1, l, r - 1); // Adjust to 0-based index
            cout << MIN.first<< " "<< MIN.second << endl;
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
