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
    cin >> n;
    vi a(n - 1, 0);
    vi hash(n + 1, 0);
    
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n - 1; i++) { 
        int diff = a[i] - a[i - 1];
        if (diff > 0 && diff <= n) {
            hash[diff]--;
        }
    }

    vi unUsed;
    int Res = 1e18;

    for (int i = 1; i <= n; i++) {
        if (hash[i] == 0) {
            unUsed.push_back(i);
        } else if (hash[i] == -1) {
            if (Res == 1e18) {
                Res = i;
            }
        }
    }
    cout<<" "<<Res<<endl;
    if (unUsed.size() > 2) {
        cout << "NO" << endl;
        return;
    }

    if (Res == n || (unUsed.size() == 2 && Res == (unUsed[0] + unUsed[1]))) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main() {
    int tt_;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
