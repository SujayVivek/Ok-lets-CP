#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int x, y;
int dp[60 + 1][2][2];

int calc(int bit, int carry_x, int carry_y) {
    if (bit > 60) {
        return (carry_x == 0 && carry_y == 0) ? 0 : -1;
    }
    if (dp[bit][carry_x][carry_y] != -2) {
        return dp[bit][carry_x][carry_y];
    }
    int x_bit = (x>>bit)&1;
    int y_bit = (y >>bit) & 1;
    int res = -1;
    for (int k_bit = 0; k_bit <= 1; ++k_bit) {
        int sum_y = y_bit+k_bit+ carry_y;
        int sum_x = x_bit + k_bit + carry_x;
        int newcx = sum_x/2;
        int sum_x_bit = sum_x%2; int newcy = sum_y / 2;
        int sum_y_bit = sum_y % 2;
        if (sum_x_bit == 1 && sum_y_bit == 1) {
            continue;
        }
        int res_nxt = calc(bit + 1, newcx, newcy);
        if (res_nxt != -1) {
            int current = (k_bit << bit) + res_nxt;
            if (res == -1 || current < res) {
                res = current;
            }
        }
    }
    return dp[bit][carry_x][carry_y] = res;
}

void Solve() {
    cin >> x >> y;
    for (int i = 0; i <= 60; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k] = -2;
            }
        }
    }
    int ans=calc(0, 0, 0);
    cout <<ans<< endl;
}

int32_t main() {
    int tt;
    cin >> tt;
    while (tt--) {
        Solve();
    }
    return 0;
}