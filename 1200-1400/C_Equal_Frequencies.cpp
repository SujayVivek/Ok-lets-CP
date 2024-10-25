#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
#define endl "\n"
#define pb push_back
#define MP make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;

struct VarVec {
    int n;
    vector<char> v;
    VarVec(int n, const vector<char>& v) : n(n), v(v) {}
};
void Solve() {
    int n; string s;cin>>n>>s;
    map<char,set<int>>mps;
    for(int i = 0; i<n; i++){
        mps[s[i]].insert(i);
    }
    map<int,vector<char>>mpp;
    for(auto it: mps){
        mpp[it.ss.size()].pb(it.ff);
    }
    vector<VarVec> vec(n+1);
    for(auto it: mpp){
        vec[i].n = it.ff;
        vec[i].v = it.ss;
    }

}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}