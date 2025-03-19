#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n; cin>>n;
    vector<vector<char>> grid(n, vector<char>(n, ' '));
    int T = 0; int i = 0, j = 0;
    while(i+T<(n+1)/2 && j+T<(n+1)/2){
        char c = (T%2==0)?'#':'.';
        for(int i = T; i<n-T; i++){
            grid[i][T] = c; grid[i][n-T-1] = c;
            grid[T][i] = c; grid[n-T-1][i] = c;
        }
        T++;
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<grid[i][j];
        }cout<<endl;
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}