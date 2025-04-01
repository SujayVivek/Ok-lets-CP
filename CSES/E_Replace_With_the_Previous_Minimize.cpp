#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

template <class T> bool ckmax(T &a, T b) {return a<b ? a=b, true : false;}
void Solve() {
    int n,k; cin >> n >> k;
    string s; cin >> s;

    char mn = 'a';
    for (int i = 0; i < n; i++) if(s[i] > mn) {
        if (s[i] - 'a' > k) {
            k -= mn - 'a';
            int to = s[i] - k;
            for (char c = s[i]; c > to; c--) {
                for (char &e:s) if (e == c) {
                    e = char(c-1);
                }
            }
            break;
        } else ckmax(mn, s[i]);
    }
    for (char &e:s) if (e <= mn) {
        e = 'a';
    }
    cout << s << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}