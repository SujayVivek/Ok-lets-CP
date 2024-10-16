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

void Solve() {
    int n, r;cin>>n>>r;
    int c = 0, p = 0, h = 0;
    loop(i,0,n){
        int x; cin>>x;
        c = x%2;
        h+=x-c;
        p+=c;
    }
    r-= h/2;
    h+= p%2;
    r-= p/2+ p%2;
    p-=p%2;
    
    while(r && p){
        r--;
        p-=2;
        h+=2;
    }
    cout<<h<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}