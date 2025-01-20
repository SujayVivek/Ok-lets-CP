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

    int mid = (n+1)/2;
    if(n==6){
        cout<<"1 1 2 3 1 2"<<endl;
    }
    else{
        for(int i = 0; i<n; i++){
            cout<<i%mid + 1<<" ";
        }cout<<endl;
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