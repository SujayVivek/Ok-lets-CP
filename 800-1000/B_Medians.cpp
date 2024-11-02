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
    int n, k;
    cin>>n>>k;
    if(n==1 && k==1){cout<<"1\n1"<<endl;return;}
    if(k==1 || k==n){cout<<-1<<endl;return;}
    if((k-1)%2==0){
        cout<<5<<endl;
        cout<<1<<" "<<2<<" "<<k<<" "<<k+1<<" "<<k+2<<endl;
    }else{
        cout<<3<<endl;
        cout<<1<<" "<<k<<" "<<k+1<<" "<<endl;
    }
    return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}