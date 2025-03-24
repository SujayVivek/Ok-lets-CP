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

    int N; cin>>N;
    if(N%2==0){
        for(int i = 0; i<N/2 -1; i++)cout<<"-";
        cout<<"==";
        for(int i = N/2 + 1;i<N; i++)cout<<"-";
    }else{
        for(int i = 0; i<N/2; i++)cout<<"-";
        cout<<"=";
        for(int i = N/2 + 1; i<N; i++) cout<<"-";
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