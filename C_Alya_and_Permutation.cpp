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
    int p = 64-__builtin_clz(n);
    vi ans;
    if(n%2==0){
        int r = (1<<(p-1))-1;
        if(n-r>=3){
                for(int i = 1; i<=n-1; i++){
                if(i==r)continue;
                ans.push_back(i);
            }
            ans.push_back(n);
            ans.push_back(r);
        }else{
            n--;
            for(int i = 2; i<=n-2; i++){
                ans.push_back(i);
            }
            ans.push_back(1);
            ans.push_back(n-1);
            ans.push_back(n);
            ans.push_back(n+1);
            n++;
        }
        
    }else{
        for(int i = 2; i<=n-2; i++){
            ans.push_back(i);
        }
        ans.push_back(1);
        ans.push_back(n-1);
        ans.push_back(n);
    }
    int k = 0;
    for(int i = 0; i<n; i++){
        if(i%2==0){
            k&=ans[i];
        }else{
            k|=ans[i];
        }
    }
    cout<<k<<endl;
    for(auto &x: ans){
        cout<<x<<" ";
    }cout<<endl;
    return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}