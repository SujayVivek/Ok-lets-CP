#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi ans;
int n;
void RightShifter(int lo, int hi){
    if(hi>n+1 || lo>n+1){
        cout<<-1<<endl;exit(0);
    }
    for(int i = lo+1; i<hi; i++){
        ans[i] = i-1;
    }
    ans[lo] = hi-1;
}
void Solve() {
    int a, b; cin>>n>>a>>b;
    ans.assign(n+1,0);
    if(a==1 || b==1){
        for(int i = 1; i<=n; i++){
            cout<<i<<" ";
        }cout<<endl;return;
    }
    else if(n%a==0){
        for(int i = 1; i<=n; i+=a){
            RightShifter(i, i+a);
        }
    }else if(n%b==0){
        for(int i = 1; i<=n; i+=b){
            RightShifter(i, i+b);
        }
    }else{
        int copy = n;
        int i = 1;
        while(copy%a!=0 && copy>0){
            RightShifter(i, i+b);
            copy-=b;
            i+=b;
        }
        while(copy!=0 && copy>0){
            RightShifter(i, i+a);
            copy-=a;
            i+=a;
        }
    }
    for(int i = 1; i<=n; i++){
        cout<<ans[i]<<" ";
    }cout<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}