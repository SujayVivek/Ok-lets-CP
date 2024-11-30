#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef vector<int> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n, k;cin>>n>>k;
    vi a(n,0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    vi pref(n,0);
    pref[0] = a[0];
    for(int i = 1; i<n; i++){
        pref[i] = pref[i-1] + a[i];
    }
    int lo = a[0], hi = a[n-1] + k, ans = -1;
    while(lo<=hi){
        int mid = (lo + hi)/2;
        int dist = lower_bound(a.begin(), a.end(), mid) - a.begin(); 
        // if(dist)dist--;
        if(dist*mid-(pref[dist])<=k){
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid -1;
        }
    }
    set<int>st;
    for(int i = 0; i<n; i++){
        if(a[i]<=ans){
            st.insert(a[i]);
        }
    }
    int c = 0;
    if(st.size()>=2) c = 2;
    else c = st.size();
    cout<< n-ans+1+c<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}