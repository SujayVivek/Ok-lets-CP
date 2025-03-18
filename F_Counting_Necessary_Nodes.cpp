#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
bool ok(int l1, int r1, int l2, int r2){
    if(l1 == r1 || l2 == r2) return true;
    else return false;
}
void Solve() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int ans = 0;
    while(true){
        if(ok(l1, r1, l2, r2)) break;
        if(l1 & 1){
            ans += (r2 - l2);
            l1 += 1;
        }
        if(ok(l1, r1, l2, r2)) break;
        if(r1 & 1){
            ans += (r2 - l2);
            r1 -= 1;
        }
        if(ok(l1, r1, l2, r2)) break;
        if(l2 & 1){
            ans += (r1 - l1);
            l2 += 1;
        }
        if(ok(l1, r1, l2, r2)) break;
        if(r2 & 1){
            ans += (r1 - l1);
            r2 -= 1;
        }
        if(ok(l1, r1, l2, r2)) break;
        l1 /= 2; r1 /= 2; l2 /= 2; r2 /= 2;
    }
    cout << ans << '\n';
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}