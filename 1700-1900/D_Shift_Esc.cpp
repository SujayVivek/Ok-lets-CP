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
    int n, m; int k;
    cin >> n >> m >> k;
    vvi grid(n, vi(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    vvi A(m, vi(m, 1e18)),B(m, vi(m, 1e18));
    for(int i=0; i<m; i++){
        A[0][i] = grid[0][i]+k*i;
    }
    for(int i=0; i<m; i++){
        if(i==0)continue;
        for(int j=0; j<m; j++){
            if( A[i][j]-A[i-1][j]>grid[0][(i+j)% m]){
                A[i][j] = A[i-1][j]+grid[0][(i+j)%m];
            }
        }
    }
    for(int i=1; i<n; i++){
        vi ans(m, 1e18);
        for(int j=0; j<m; j++) {
                for(int k=0; k<m; k++) {
                    if(A[j][k]<ans[j]){
                        ans[j]=A[j][k];
                    }
                }
            }
        for(int o=0; o<m; o++){
            for(int j=0; j<m; j++){
                int res=grid[i][(j+o)% m];
                if(j!=0){
                    B[j][o] = min(B[j][o], min(B[j-1][o]+res, ans[j]+k*o+res));
                }
                if(2*B[j][o]>2*(res+k*o+ans[j])){
                        B[j][o]=res+k*o+ans[j];
                    }
                }
            }
        swap(A,B);
        for(int j = 0; j<m; j++){
            for(int k = 0; k<m; k++){
                B[j][k] = 1e18;
            }
        }
    }
    for(int i=0; i<m; i++) {
        A[m-1][0] = min(A[m-1][0], A[m-1][i]);
    }cout <<A[m-1][0]<< endl;
    
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