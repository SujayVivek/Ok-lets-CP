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
    int n, k; cin>>n>>k;
    int pass = 0;
    map<int,int> mpp;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        mpp[x]++;
    }
    priority_queue<int> pq;
    for(auto it: mpp){
        pq.push(it.second);
    }
    while(!pq.empty()){
        int Top = pq.top(); 
        if(Top>=k){
            pass+= k-1;
            Top-=k;
            pq.pop();
            if(Top) pq.push(Top);
        }
        else if(Top+pass>=k){
            pass-=(k-Top);
            pass+= k-1;
            pq.pop();
        }
        else if(Top+pass<k){
            break;
        }
    }
    int ans = 0;
    while(!pq.empty()){
        ans+= pq.top();
        pq.pop();
    }
    cout<<ans + min(pass, k-1)<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}