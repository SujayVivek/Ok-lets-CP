#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n, m; 

void Solve() {
    cin>>n>>m;
    vvi a(n, vi(m,0));
    int M[n][m][10];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>a[i][j];
            M[i][j][0] = a[i][j];
        }
    }
    //preprocess
    for(int k=1;k<=log2(min(n,m));k++){
            for(int i=0;i+(1<<k)<=n;i++){
                for(int j=0;j+(1<<k)<=m;j++){
                    M[i][j][k]=min(min(M[i][j][k-1],M[i+(1<<(k-1))][j][k-1]),min(M[i][j+(1<<(k-1))][k-1],M[i+(1<<(k-1))][j+(1<<(k-1))][k-1]));
                }
            }
        }
    //query
    int l=1;
        int r=min(n,m);
        while(l<r){
            int x=(l+r+1)/2;
            int z=0;
            int p=log2(x);
            for(int i=0;i+x<=n;i++){
                for(int j=0;j+x<=m;j++){
                    if(min(min(M[i][j][p],M[i+x-(1<<p)][j+x-(1<<p)][p]),min(M[i][j+x-(1<<p)][p],M[i+x-(1<<p)][j][p]))>=x){
                        z=1;
                    }
                }
            }
            if(z){
                l=x;
            }
            else{
                r=x-1;
            }
        }
        cout<<l<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}