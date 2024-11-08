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
#define int long long
void Solve() {
    int n, m;cin>>n>>m;
    string s; cin>>s;
    //taking all 6 permutations of abc combinations
    vvll v(6, vll(n+1,0));
    string a = "abc";
    int cnt = 0;
    do{
        for(int i = 0; i<n; i++){
            v[cnt][i+1] += v[cnt][i] + (s[i]!=a[i%3]);
        }
        cnt++;
    }while(next_permutation(all(a)));

    while(m--){
        int l, r;cin>>l>>r;
        int ans = n;
        for(int  i= 0; i<6; i++){
            ans = min(v[i][r]-v[i][l-1], ans);
        }
        cout<<ans<<endl;
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