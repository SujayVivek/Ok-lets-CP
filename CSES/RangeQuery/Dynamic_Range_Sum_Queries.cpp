#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi a; 
vi SegTree;

void build(int idx, int l, int r){
    if(l==r){
        SegTree[idx] = a[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(2*idx, l, mid);
    build(2*idx + 1, mid + 1, r);
    SegTree[idx] = SegTree[2*idx] + SegTree[2*idx + 1];
}
void update(int idx, int l, int r, int pos, int val){
    if(pos<l || pos>r) return;
    if(l==r){
        SegTree[idx] = val;
        a[l] = val;
        return;
    }
    int mid = l + (r-l)/2;
    update(idx*2, l, mid, pos, val);
    update(2*idx + 1, mid + 1, r, pos, val);
    SegTree[idx] = SegTree[2*idx] + SegTree[2*idx + 1];
}
int query(int idx, int l, int r, int lq, int rq){
    if(r<lq || l>rq) return 0;
    if(l>=lq && r<=rq) return SegTree[idx];
    int mid = (r-l)/2 + l;
    return query(2*idx, l, mid, lq, rq) + query(2*idx + 1, mid + 1, r, lq, rq);
}
void Solve() {
    int n, q; cin>>n>>q;
    a.assign(n,0), SegTree.assign(4*n+1, 0);
    for(int i = 0; i<n; i++)cin>>a[i];
    build(1, 0, n-1);
    while(q--){
        int c; cin>>c;
        if(c == 1){
            int k , u; cin>>k>>u;
            update(1, 0, n-1, k-1, u);
        }else{
            int lq, rq; cin>>lq>>rq;
            cout<< query(1, 0, n-1, lq-1, rq-1)<<endl;
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