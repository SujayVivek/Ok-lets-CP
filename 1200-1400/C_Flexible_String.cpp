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
// typedef int long long;
string a, b;
string v;
bool bools[26];
ll ans, k;
 
ll counter()
{
    ll anz = 0, l = 0;
    for(ll i = 0; i < a.size(); i++) {
        if(a[i] == b[i] || bools[ a[i]-'a' ])
            l++;
        else {
            anz += l*(l+1)/2;
            l = 0;
        }
    }
    anz += l*(l+1)/2;
    return anz;
}
 
void solve(ll pos, ll cnt)
{
    if(cnt > k) return;
    if(pos == v.size()) {
        if(cnt == k) ans = max(ans,counter());
        return;
    }
    solve(pos+1, cnt);
    bools[ v[pos]-'a' ] = 1;
    solve(pos+1, cnt+1);
    bools[ v[pos]-'a' ] = 0;
}
 
int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n; cin >> n >> k;
        cin >> a >> b;
        unordered_set <char> us;
        for(auto &ch : a) us.insert(ch);
        v.clear();
        for(auto &x : us) v.pb(x);
        k = min(k, (ll)us.size());
        memset(bools, 0, sizeof bools);
        ans = 0;
        solve(0, 0);
        cout << ans << endl;
    }
    return 0;
}
