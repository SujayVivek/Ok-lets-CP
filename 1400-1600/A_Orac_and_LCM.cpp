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
#define int long long
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;

int lcm(int a, int b){
    return a*b/__gcd(a,b);
}
void Solve() {
    int N;cin>>N;
    vi A(N,0);
    for(auto &x: A)cin>>x;
    vi gcds(N,0);
    gcds[N-1] = A[N-1];
    for(int i = N-2; i>=0; i--){
        gcds[i] = __gcd(gcds[i+1], A[i]);
    }
    vi terms(N,0);
    for(int i = 1; i<N; i++){
        terms[i-1] = lcm(A[i-1],gcds[i]);
    }
    int ans = 0;
    for(int i = 0; i<N-1; i++){
        ans = __gcd(terms[i],ans);
    }
    cout<<ans<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}