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
    int n;cin>>n;
    string s;cin>>s;
    vvi v;
    int c = 0, d = 0;
    for(int i = 0; i<n; i++){
        if(s[i]=='0'){
            c++;
            if(!d){
                v.pb({1,d});
                d = 0;
            }
        }else{
            d++;
            if(!c){
                v.pb({0,c});
                c = 0;
            }
        }
    }
    int p = v.size();
    int c = 0, d = 0;
    for(int i = 0; i<p ;i++){
        if(v[i][0] == 1){
            if(c){
                
            }
        }
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