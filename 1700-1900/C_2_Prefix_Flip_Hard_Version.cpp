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
    int n; 
    string a, b; 
    cin >> n >> a >> b;
    vector<int> A, B;
    a += '0'; b += '0';
    for(int i = 1; i <= n; i++) {
        if(a[i] != a[i - 1]) A.push_back(i);
        if(b[i] != b[i - 1]) B.push_back(i);
    }
    A.insert(A.end(), B.rbegin(), B.rend());
    cout << A.size();
    for(int x : A) {
        cout <<" "<< x;
    }
    cout << '\n';
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}