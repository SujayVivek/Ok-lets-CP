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
    int arr[n], grid[n][n];
    for(int i = 0; i<n; i++){
        arr[i] = (1<<30)-1;
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>grid[i][j];
            if(i!=j){
                arr[i]&= grid[i][j];
                arr[j]&= grid[i][j];
            }
        }
    }
    if(n==1){
        cout<<"YES\n1"<<endl;return;
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i!=j){
                if((arr[i]|arr[j])!=grid[i][j]){
                    cout<<"NO"<<endl;return;
                }
            }
        }
    }
    cout<<"YES"<<endl;
    for(auto x: arr)cout<<x<<" ";
    cout<<endl;
    
}


int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}