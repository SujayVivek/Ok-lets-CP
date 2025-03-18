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
    int n; cin>>n; int ans;
    vi a = {1, 2, 3}; int i = 0;
    while(true){
        cout<<"?"<<" "<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
        cin>>ans;
        if(ans == 0)break;
        a[i] = ans; i = rand()%3;
    }  
    cout<<"!"<<" "<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}