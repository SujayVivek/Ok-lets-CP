#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

set<string> stru;
void crosser(int a, int b, vector<int>&v1, vector<int>&v2, string s){
    for(int i = 0; i<b; i++){
        for(int j = 0; i<a; i++){
            if(v1[j]<v2[i]){
                stru.insert(s.substr(v1[j]+1, v2[i]-v1[j]+1));
            }else{
                stru.insert(s.substr(v2[i]+1, v1[j]-v2[i]));
            }
        }
    }
}
void singler(int a, vector<int>&v1, bool ok, string s){
    for(int i = 0;i<a; i++){
        for(int j = i+1; j<a; j++){
            if(ok){
                stru.insert(s.substr(v1[i]+1,v1[j]-v1[i]));
            }else{
                stru.insert(s.substr(v1[i]+1,v1[j]-v1[i]+1));
            }
        }
    }
}
void Solve() {
    int n; cin>>n;
    string s; cin>>s;
    vi pref(n,0);
    pref[0] = (s[0]=='+')?+1:-1;
    map<int, vi>mpp;
    map<int,vi>mpp_;
    mpp[pref[0]].push_back(0);
    for(int i = 1; i<n; i++){
        pref[i] = pref[i-1] + s[i]=='+'?1:-1;
        mpp[pref[i]].push_back(i);
        if(s[i]=='-' && s[i-1]=='-'){
            mpp_[pref[i-1] + 2].push_back(i-1);
        }
    }
    stru.clear();
    for(auto it: mpp){
        if(it.first ==0){
            for(auto it2: it.second){
                stru.insert(s.substr(0,it2));
            }
            for(auto it2: mpp_[it.first]){
                stru.insert(s.substr(0, it2+1));
            }
        }
        vector<int> v1 = it.second;
        vector<int> v2 = mpp_[it.first];
        int a = v1.size(), b = v2.size();
        singler(a, v1, true , s);
        singler(b, v2, false, s);
        crosser(a, b, v1, v2, s);
    }
    cout<<stru.size()<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}