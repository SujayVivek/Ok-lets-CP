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
    int q;
    cin >> q;
    deque<int> dq;
    bool rev = 0;
    int sum = 0, ans = 0;
    int n = 0;
    while(q --){
        int s; cin >> s;
        if(s == 3){
            int k; cin >> k;
            sum += k;
            n++;
            if(rev){
                dq.push_front(k);
            }
            else{
                dq.push_back(k);
            }
            ans += k * n;
            cout << ans << endl;   	
        }
        if(s == 2){
            rev = !rev;
            ans = (n + 1) * sum - ans;
            cout << ans << endl;
        }
        if(s == 1){
            if(rev){
                ans += sum - dq.front() * n;
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else{
                ans += sum - dq.back() * n;
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cout << ans << endl;
        }
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