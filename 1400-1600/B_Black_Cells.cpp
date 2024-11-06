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
#define int long long
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;

int n;
int check(int mid, vi &a){
    bool ok = true;
    int i = 0, j = 1;
    while(i<n && j<n){
        if(a[j]-a[i]>mid && ok){
            i++; j++;
            ok = false;
        }else if(a[j]-a[i]<=mid){
            i+=2; j+=2;
        }else{
            return 0;
        }
    }
    return 1;
}
void Solve() {
    cin>>n;
    vll A(n, 0);
    for(auto &x: A)cin>>x;
    sort(all(A));
    if(n==1){cout<<1<<endl;return;}
    if(n==2){cout<<A[1]-A[0]<<endl;return;}
    int hi = 1e18;
    int lo = 0;
    int ans = 0;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid, A)){
            ans = mid; 
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}