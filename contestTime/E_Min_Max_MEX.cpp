#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

bool check(int mex, vi &a, int k, int n ){
    int mex_ = 0;
    set<int> st;
    for(int i = 0; i<n; i++){
        if(a[i]<mex && !st.count(a[i])) {mex_++;}
        st.insert(a[i]);
        if(mex_==mex){
            st.clear(); mex_= 0; k--;
        }
    }
    if(k<=0) return true;
    else return false;
}
void Solve() {
    int n, k; cin>>n>>k;
    vi a(n,0);
    for(int i = 0; i<n; i++) cin>>a[i];
    vi b = a; sort(b.begin(), b.end());
    int mex = 0;
    for(int i = 0; i<n; i++){
        if(b[i]==mex) mex++;
        else if(b[i]>mex) break;
    }
    if(k==1) {cout<<mex<<endl;return;}
    int lo = 0, hi = mex; int ans = 0;
    while(lo<=hi){
        int mid = (hi - lo)/2 + lo;
        if(check(mid, a, k, n)){
            lo = mid + 1;
            ans = mid;
        }else{
            hi = mid - 1; 
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}