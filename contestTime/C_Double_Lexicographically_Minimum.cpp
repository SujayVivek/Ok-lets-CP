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
    int n = s.length();
    map<char,int> mpp;
    for(int i = 0; i<s.length(); i++){
        mpp[s[i]]++;
    }
    vector<char> ans(n);
    auto it = mpp.begin();
    if(it->second == 1){
        mpp[it->first]--;
        ans[n-1] = it->first;
        int idx = 0;
        for(auto it2: mpp){
            while(it2.second>0){
                ans[idx] = it2.first;
                mpp[it2.first]--;
                idx++;
            }
        }
    }else{
        ans[0] = it->first, ans[n-1] = it->first;
          
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