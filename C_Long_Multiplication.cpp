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
    string x, y;cin>>x>>y;
    bool ok = true;
    bool small_x = true;
    loop(i,0,x.length()){
        if(x[i]==y[i] && ok)continue;
        if(ok){
            ok = false;
            if(x[i]>y[i]){
                small_x = false;
            }
            continue;
        }
        if(small_x){
            if(x[i]<y[i]){
                int temp = x[i];
                x[i] = y[i];
                y[i] = temp;
            }
        }else{
           if(x[i]>y[i]){
                int temp = x[i];
                x[i] = y[i];
                y[i] = temp;
            } 
        }
    }
    cout<<x<<endl<<y<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}