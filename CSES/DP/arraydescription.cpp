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
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll N, M;
vector<ll> arr;
vector<vector<ll>> dp;
ll calc(int i, int val) {
    if (val < 1 || val > M) return 0;
    if (i == 0) {
        if (arr[i] == 0 || arr[i] == val) return 1;
        else return 0;
    }
    if (dp[i][val] != -1) return dp[i][val];
    if (arr[i] == 0) {
        dp[i][val] = (calc(i - 1, val - 1) + calc(i - 1, val) + calc(i - 1, val + 1)) % mod;
    } else {
        if (arr[i] == val)
            dp[i][val] = (calc(i - 1, val - 1) + calc(i - 1, val) + calc(i - 1, val + 1)) % mod;
        else
            dp[i][val] = 0;
    }
    return dp[i][val];
}

int main() {
    cin>>N>>M;
    arr.assign(N, 0);
    for(auto &p: arr)cin>>p;
    dp.assign(N, vector<ll>(M + 1, -1));
    ll ans = 0;
    for (int val = 1; val <= M; val++) {
        ans = (ans + calc(N - 1, val)) % mod;
    }
    cout << ans << endl;
    return 0;
}
