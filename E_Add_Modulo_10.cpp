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
    vi a(n,0);
    for(auto &x: a)cin>>x;
    sort(a.begin(),a.end());
    bool ok = false;
    for(int i = 0; i<n; i++){
        if(a[i]%10==5){ a[i]+=5; ok = true;}
        else if(a[i]%10==0){ok = true; continue;}
        else{
            while(a[i]%10!=2){
                a[i]+=(a[i]%10);
            }
        }
    }
    if(ok){
        for(int i = 0; i<n-1; i++){
            if(a[i]!=a[i+1]){
                cout<<"No"<<endl; return;
            }
        }
        cout<<"Yes"<<endl;return;
    }else{
        set<int> st;
        for(int i = 0; i<n; i++){
            st.insert((a[i]/10)%2);
        }
        if(st.size()==1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
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