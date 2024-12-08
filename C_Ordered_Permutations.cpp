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
    int n, k; cin>>n>>k;
    if(n<50 && k>(1ll<<(n-1))){
        cout<<-1<<endl;return;
    }
    k--;
    deque<int> dq;
    dq.push_back(n);
    for(int i = 0; i<n-1; i++){
        if(i<50){
            if( (k&(1ll<<i))){
                dq.push_back(n-1-i);
            }else{
                dq.push_front(n-1-i);
            }
        }else{
            dq.push_front(n-1-i);
        }
    }
    for(auto &v: dq){
        cout<<v<<" ";
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}