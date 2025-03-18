#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi SegTree, a;
void build(int idx, int l, int r){
    if(l==r){
        SegTree[idx] = a[l]; return;
    }
    int mid = l + (r-l)/2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    SegTree[idx] = __gcd(SegTree[2*idx], SegTree[2*idx + 1]);
}
int query(int idx, int l, int r, int lq, int rq){
    if(r<lq || l>rq) return 0;
    if(l>=lq && r<=rq) return SegTree[idx];
    int mid = l + (r-l)/2;
    return __gcd(query(2*idx, l, mid, lq, rq), query(2*idx + 1, mid+1, r, lq, rq));
}
void Solve() {
    int n, q; cin>>n>>q;
    SegTree.resize(4*n+5);
    a.resize(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    build(1, 0, n-1);
    while(q--){int l, r; cin>>l>>r; l--, r--;cout<<query(1, 0, n-1, l , r)<<" ";} cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}