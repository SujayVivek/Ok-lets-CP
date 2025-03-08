#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

struct dsu {
    vector<int> e;
    dsu(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};
void Solve() {
    int n; cin>>n;
    vi p(n,0); for(auto &x: p) cin>>x;
    dsu d(n);
    for(int i = 0; i<n; i++){
        p[i]--; d.join(i, p[i]);
    }
    set<int> cy;
    for(int i = 0; i<n; i++){
        cy.insert(d.find(i));
    }
    int cycles = cy.size();
    for(int i = 1; i<n; i++){
        if(d.sameSet(p[i], p[i-1])){
            cout<<n-(cycles+1)<<endl;return;
        }
    }
    cout<<n-(cycles - 1)<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}