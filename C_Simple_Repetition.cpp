#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

// vector<int> isPrime(1e9+5, 1);

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
void Solve() {
    int n, k; cin>>n>>k; string p = "";
    string s = to_string(n); for(int i = 0; i<k; i++) p+= s;
    if((k==1 && is_prime(n)) || (n==1 && is_prime(stoi(p)))){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}