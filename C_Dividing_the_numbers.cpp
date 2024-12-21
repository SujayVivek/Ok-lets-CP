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
    set<int>A, B; int sumA = 0, sumB = 0;
    for(int i = n; i>0; i--){
        if(sumA<=sumB){
            sumA+=i; A.insert(i);
        }else{
            sumB+=i; B.insert(i);
        }
    }
    cout<<abs(sumA-sumB)<<endl;
    cout<<A.size()<<" ";
    for(auto it: A){
        cout<<it<<" ";
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}