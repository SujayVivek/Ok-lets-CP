#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n, k; 
bool check(int mid, vi &A, vi &B){
    int num_users = upper_bound(A.begin(), A.end(), mid) - A.begin() ;
    int num_neg = upper_bound(B.begin() + num_users, B.end(), mid) - B.begin() - num_users ;
    if(num_neg>k) return 0;
    else return 1;
}
void Solve() {
    cin>>n>>k;
    vvi a(n, vi(2, 0));
    int hi = 0, lo = 1e9;
    for(int i = 0; i<n; i++){
        cin>>a[i][1];
        lo = min(lo, a[i][1]);
    }for(int i = 0; i<n; i++){
        cin>>a[i][0];
        hi = max(hi, a[i][0]);
    }
    sort(a.begin(), a.end());
    vi A, B;
    for(int i = 0; i<n; i++){
        A.push_back(a[i][0]);
        B.push_back(a[i][1]);
    }
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(check(mid, A, B)){
            ans = mid;
            lo = mid +1;
        }else{
            hi = mid -1;
        }
    }
    if(ans==-1){
        cout<<0<<endl;return;
    }
    cout<< ans*(n-(upper_bound(A.begin(), A.end(), ans) - A.begin()))<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}