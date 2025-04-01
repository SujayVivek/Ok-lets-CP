#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const ll N = 20;
ll dp[N][10][2][2]; 
 
void reset () {memset(dp, -1, sizeof(dp));}
 
ll calc(string &S, ll n, ll x, bool leading_zero, bool hi) {
    if (n == 0) return 1;
    if (x != -1 && dp[n][x][leading_zero][hi] != -1) 
        return dp[n][x][leading_zero][hi];
    int hiLim =  hi ? (S[S.length() - n] - '0') : 9;
 
    ll ans = 0;
    for (int digit = 0; digit <= hiLim; digit++) {
        if ((digit == x) && (leading_zero == 0)) continue;

        ans += calc(S, n - 1, digit, (leading_zero && digit == 0), (hi && (digit == hiLim)));
    }
 
    return dp[n][x][leading_zero][hi] = ans;
}
 
int main() {
	ll a, b; cin >> a >> b;
 
    string a_str = to_string(a - 1);
    string b_str = to_string(b);
 
    reset();
    ll ans1 = calc(a_str, a_str.length(), -1, 1, 1);
    reset();
    ll ans2 = calc(b_str, b_str.length(), -1, 1, 1);
    cout << ans2 - ans1 << "\n";
    return 0;
}
