#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef vector<int> vi;
#define int long long
#define endl "\n"

const int N = 501;
int dp[N][N];
int calc(int a, int b){
    if(a>b) swap(a,b);
    if(dp[a][b] != 1e9)     return dp[a][b];
    if(a == b)              return dp[a][b] = 0;
    if(a == 1 || b == 1)    return dp[a][b] = (a == 1 ? b-1 : a-1);
    for(int i = 1; i < a; i++)
        dp[a][b] = min(dp[a][b], calc(i, b)+calc(a-i, b) + 1);
    for(int i = 1; i < b; i++)
        dp[a][b] = min(dp[a][b], calc(a, i)+calc(a, b-i) + 1);
    return dp[a][b];
}
void Solve() {
    int a,b;cin>>a>>b;
    fill(&dp[0][0], &dp[0][0] + N * N, 1e9);
    int result = calc(max(a,b), min(a,b));
    cout<<result<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}