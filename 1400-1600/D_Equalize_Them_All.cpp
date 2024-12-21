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
    map<int,set<int>>mpp;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mpp[a[i]].insert(i);
    }
    int mx = 0; set<int> Max; int maxEle = 0;
    for(auto it: mpp){
        if(it.second.size()>=mx){
            mx = it.second.size();
            Max = it.second;
            maxEle = it.first;
        }
    }
    cout<<n-Max.size()<<endl;
    auto it = Max.begin();
    int i = *it, j = *it; i--, j++;
    while(i>=0){
        if(a[i]==maxEle){i--;continue;}
        if(a[i]<a[i+1]){
            cout<<1<<" "<<i+1<<" "<<i+2<<endl;
        }   
        else if(a[i]>a[i+1]){
            cout<<2<<" "<<i+1<<" "<<i+2<<endl;
        }
        a[i] = maxEle;
        i--;
    }
    while(j<n){
        if(a[j]==maxEle){ j++; continue;}
        if(a[j]>a[j-1]){
            cout<<2<<" "<<j+1<<" "<<j<<endl; 
        }else if(a[j]<a[j-1]){
            cout<<1<<" "<<j+1<<" "<<j<<endl;
        }
        a[j] = maxEle;
        j++;
    }

}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}