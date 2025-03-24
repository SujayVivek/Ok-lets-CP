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
    int mx = -1, mn = -1;
    int T = n; int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i<=2; i++){
        if(T%4==0){
            mx = T/4; break;
        }else{
            T-=6;
            cnt1++;
        }
    } T = n;
    for(int i = 1; i<=3; i++){
        if(T%6==0){
            mn = T/6; break;
        }else{
            T-=4;
            cnt2++;
        }
    }
    if(mn==-1 || mx==-1){
        cout<<-1<<endl;
    }else{
        cout<< mn+cnt2<<" "<<mx+cnt1<<endl;
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