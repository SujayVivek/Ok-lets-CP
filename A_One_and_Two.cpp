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
    map<int,int> mpp;
    vi a(n,0);
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        a[i] = x;
        mpp[x]++;
    }
    if(mpp[2]%2==0){
        int cnt = 0;
        int i;
        for( i = 0; i<n; i++){
            if(a[i]==2)cnt++;
            if(cnt == mpp[2]/2)break;
        }
        cout<<i+1<<endl;
    }else{
        cout<<-1<<endl;
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