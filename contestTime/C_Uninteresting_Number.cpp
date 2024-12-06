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
    string n; cin>>n;
    int sum = 0;
    map<int,int> mpp;
    for(int i = 0; i<n.length(); i++){
        sum+= (n[i]-'0');
        mpp[n[i]-'0']++;
    }
    if(sum%9==0){
        cout<<"YES"<<endl;return;
    }
    int rem1 = 9 + (9-sum%9);
    int rem2 = 9-sum%9;
    set<int>st;
    for(int i = 0; i<=mpp[2]; i++){
        st.insert(2*i);
        if(i>30)break;
    }
    
    if(st.find(rem1)!=st.end() || st.find(rem2)!=st.end()){
        cout<<"YES"<<endl;return;
    }
    for(int i = 1; i<=min(mpp[3],3ll); i++){
        if(st.find(rem1-i*6)!=st.end() || st.find(rem2-i*6)!=st.end()){
            cout<<"YES"<<endl;return;
        }
    }
    cout<<"NO"<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}