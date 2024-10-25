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

     map<int,int> mpp;

void swap(vll &p, ll i, ll j){
    mpp[p[i]] = j;
    mpp[p[j]] = i;
     ll temp = p[i];
     p[i] = p[j];
     p[j] = temp;
}
void Solve() {
     ll n;cin>>n;
     vll p(n+1,0);
     for(int i = 1; i<=n ; i++){
        cin>>p[i];
        mpp[p[i]] = i;
     }
    ll c = 0;

    for(int i = 1 ; i<=n; i++){
        if(p[i]==i || p[p[i]]==i)continue;
        swap(p,p[i],mpp[i]);c++;
    }
    cout<<c<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}