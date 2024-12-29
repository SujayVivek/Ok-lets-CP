#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"


int modInverse(int a, int m) {
    int res = 1, p = m - 2; // m must be a prime number
    while (p > 0) {
        if (p % 2) res = (res * a) % m; // If p is odd, multiply a with result
        a = (a * a) % m;                // Square a
        p /= 2;                         // Divide p by 2
    }
    return res;
}
void Solve() {
        int n, q; cin>>n>>q;
        vector<int>A, B;
        map<int,int> mpA, mpB;
        for(int i = 0; i<n; i++){
            int x; cin>>x;
            A.push_back(x);
            mpA[i+1] = x;
        }
        for(int i = 0; i<n; i++){
            int x; cin>>x;
            B.push_back(x);
            mpB[i+1] = x;
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int prod = 1;
        for(int i = 0; i<n; i++){
            prod = (prod*min(A[i], B[i]))%mod;
        }
        cout<<prod<<" ";
        while(q--){
            int a, b; cin>>a>>b;
            if(a==1){
                int dis = upper_bound(A.begin(), A.end(), mpA[b]) - A.begin() - 1;
                mpA[b]++;
                int prev = A[dis]; int New = prev + 1;
                A[dis] = New;
                prod = (((prod*modInverse(min(prev, B[dis]), mod))%mod)*min(New, B[dis]))%mod;
            }else{
                int dis = upper_bound(B.begin(), B.end(), mpB[b]) - B.begin() - 1;
                mpB[b]++;
                int prev = B[dis]; int New = prev + 1;
                B[dis] = New;
                prod = (((prod*modInverse(min(prev, A[dis]), mod))%mod)*min(New, A[dis]))%mod;
            }
            cout<<prod<<" ";
        }cout<<endl;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}