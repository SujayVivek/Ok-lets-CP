
// int main() {
//     // ios::sync_with_stdio(0), cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;vi a(n,0);
//         for (int i = 1; i <= n; i++) {
//             cin >> a[i];
//         }
//         int t1 = INT_MAX, t2 = INT_MAX;
//         int ans = 0;
//         for (int i = 1; i <=n; i++) {
//             if (t1 > t2) {
//                 swap(t1, t2);
//             }
//             if (a[i] <= t1) {
//                 t1 = a[i];
//             } else if (a[i] <= t2) {
//                 t2 = a[i];
//             } else {
//                 t1 = a[i];
//                 ans++;
//             }
//         }
//         cout << ans << '\n';
//     }
// }
#include <bits/stdc++.h> 
using namespace std;

const int INF = 1000000005;
const int MAXN = 200005;

int t;
int n;
int a[MAXN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int t1 = INF, t2 = INF;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (t1 > t2) {
                swap(t1, t2);
            }
            if (a[i] <= t1) {
                t1 = a[i];
            } else if (a[i] <= t2) {
                t2 = a[i];
            } else {
                t1 = a[i];
                ans++;
            }
        }
        cout << ans << '\n';
    }
}