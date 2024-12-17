#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

struct Me {
    string s;
    int score;
    Me(int score = 0, string s = "") : s(s), score(score) {}
};

bool priority(const Me &a, const Me &b) {
    if (a.score == b.score) {
        return a.s < b.s; 
    } else {
        return a.score > b.score; 
    }
}

vi v(5, 0); 
vector<Me> vP;
void calc(int ind, int score, string p) {
    if (ind == 5) { 
        vP.push_back(Me(score, p));
        return;
    }
    calc(ind + 1, score + v[ind], p + (char)('A' + ind));  
    calc(ind + 1, score, p);
}

void Solve() {
    for (int i = 0; i < 5; i++) cin >> v[i]; 
    vP.clear();
    calc(0, 0, ""); 
    sort(vP.begin(), vP.end(), priority);
    for (auto &x : vP) {
        cout << x.s <<endl; 
    }
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
