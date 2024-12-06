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
    string s; cin>>s;
    map<char,int> mpp;
    int j = 0;
    for(int i = 0; i<s.length(); i++){
        j = i+1;
        mpp[s[i]]++;
        if(mpp.size()==3){
            break;
        }
    }
    if(mpp.size()==3){
        cout<<s.substr(0,j)<<endl;return;
    }
    cout<<-1<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}