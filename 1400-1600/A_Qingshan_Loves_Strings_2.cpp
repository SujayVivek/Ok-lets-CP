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
    int n; cin >> n;
    string s; 
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < s.length(); ++i) {
      cnt0 += s[i] == '0';
      cnt1 += s[i] == '1';
    }
    if (cnt0 != cnt1) {
      cout << -1 << endl;
      return;
    }
    vector<int> ans;
    deque<char> q;
    for (int i = 0; i < s.length(); ++i)
      q.push_back(s[i]);
    
    int d = 0;
    while (!q.empty()) {
      if (q.front() == q.back()) {
        if (q.front() == '0') {
          q.push_back('0');
          q.push_back('1');
          ans.push_back(n - d);
        } else {
          q.push_front('1');
          q.push_front('0');
          ans.push_back(0 + d);
        }
        n += 2;
      }
      while (!q.empty() && q.front() != q.back()) {
        q.pop_back();
        q.pop_front();
        ++d;
      }
    }
  
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i]<<" ";
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}