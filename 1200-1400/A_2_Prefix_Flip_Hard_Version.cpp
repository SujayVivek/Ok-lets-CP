#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
int n; string a, b;
void Solve() {
    cin >> n >> a >> b;
        vector<int> ops;
        for(int i = n - 1; i >= 0; i--) {
            if(a[i] != b[i]) {
                if(a[0] == b[i]) {
                    ops.push_back(1);
                    a[0] = '0' + !(a[0] - '0');
                }
                reverse(a.begin(), a.begin() + i + 1);
                for(int j = 0; j <= i; j++) {
                    a[j] = '0' + !(a[j] - '0');
                }
                ops.push_back(i + 1);
            }
        }
        cout << ops.size() << ' ';
        for(int x : ops) {
            cout << x << ' ';
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