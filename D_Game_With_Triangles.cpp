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
    int n, m; cin>>n>>m;
    vi a(n,0), b(m,0);
    for(auto &x: a)cin>>x;
    for(auto &x: b)cin>>x;
    vi sum_a, sum_b;
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    int p = 0, q = n - 1;
    while (p < q)
    {
        sum_a.push_back(a[q] - a[p]);
        p++;
        q--;
    }
    p = 0, q = m - 1;
    while (p < q)
    {
        sum_b.push_back(b[q] - b[p]);
        p++;
        q--;
    }
    for(int i = 1; i<sum_a.size(); i++){
        sum_a[i]+= sum_a[i-1];
    }
    for(int i = 1; i<sum_b.size(); i++){ 
        sum_b[i]+= sum_b[i-1];
    }
    vi ans;
    for(int k = 1; ;k++){
        int low = max(2*k-m, 0LL);
        int high = min(n-k, k);
        if(low>high)break;
        while(high-low>2){
            int mid1 = (2 * low + high) / 3;
            int mid2 = (low + 2 * high) / 3;
            int v1 = sum_a[mid1] + sum_b[k-mid1];
            int v2 = sum_a[mid2] + sum_b[k-mid2];
            if(v1<=v2){
               low = mid1;
            }else{
                high = mid2;
            }
        }
        int Ans = 0;
        for(int i = low; i<=high; i++){
            Ans = max(Ans, sum_a[i] + sum_b[k-i]);
        }
        ans.push_back(Ans);
    }
    cout<<ans.size()<<endl;
    for(int x: ans)cout<<x<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}