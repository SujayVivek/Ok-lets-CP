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
    int n, m, k; cin>>n>>m>>k;
    vi a(n,0), b(m,0);
    for(auto &x: a) cin>>x;
    for(auto &x: b) cin>>x;
    map<int,int> mp;
    multiset<int> ms;
    for(int i = 0; i<m; i++){
        mp[b[i]]++;
        ms.insert(b[i]);
    }
    int Size = ms.size();
    multiset<int> k_cnt, ext;
    int i = 0, j = 0;
    while(j<m){
        auto it = ms.find(a[j]);
        if(it!=ms.end()){
            k_cnt.insert(a[j]);
            ms.erase(it);
        }else{
            ext.insert(a[j]);
        }
        j++;
    }
    int cnt = 0; if(k_cnt.size()>=k) cnt++;
    while(j<n && i<n){
        auto it1 = ext.find(a[i]), it2 = k_cnt.find(a[i]);
        if(it1!=ext.end()){
            ext.erase(it1);
        }else if(it2!=k_cnt.end()){
            k_cnt.erase(it2);
            ms.insert(a[i]);
        }
        auto it = ms.find(a[j]);
        if(it!=ms.end()){
            k_cnt.insert(a[j]);
            ms.erase(it);
        }else{
            ext.insert(a[j]);
        }
        if(k_cnt.size()>=k) cnt++;
        i++, j++;
    }
    cout<<cnt<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}