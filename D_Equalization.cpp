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
    int x, y; cin>>x>>y;
    int i = 64-__builtin_clz(x), j = 64-__builtin_clz(y);
    vector<pair<int,int>>vp;
    vp.emplace_back(i, j);
    while(i>0 && j>0){
        if((x&(1<<i)) == (y&(1<<j))){
            vp.emplace_back(i-1, j-1);
            i--, j--;
        }else{
            break;
        }
    }
    int Ans = 1e18;
    reverse(vp.begin(), vp.end());
    for(int i = 0; i<vp.size(); i++){
        int T = vp[i].first, Q = vp[i].second;
        if(T>Q){
            int T1 = T/2, T2 = T-T1; if(T1==T2) T1--, T2++;
            int Q1 = Q/2, Q2 = Q-Q1; if(Q1==Q2) Q1--, Q2++;
            int cT1 = T1, cT2 = T2;
            while(T1!=Q1 && T1!=Q2 && T2!=Q1 && Q2!=T2){
                T1--, T2++;
            }
            while(Q1!=cT1 && Q1!=cT2 && Q2!=cT2 && Q2!=cT1){
                Q1--, Q2++;
            }
            Ans = min(1LL*(1<<T1 + 1<<T2), Ans);
            Ans = min(1LL*(1<<Q1 + 1<<Q2), Ans);
        }
    }cout<<Ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}