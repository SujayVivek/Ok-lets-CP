#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

struct Group {
    int current_nest;
};

void Solve(){
    int N, Q;
    cin >> N >> Q;
    vector<Group> groups(N + 1);
    vector<Group*> nest_ptr(N + 1);
    vector<Group*> pig(N + 1);
    for (int i = 1; i <= N; ++i) {
        groups[i].current_nest = i;
        nest_ptr[i] = &groups[i];
        pig[i] = nest_ptr[i];
    }
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            cin >> a >> b;
            pig[a] = nest_ptr[b];
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            swap(nest_ptr[a], nest_ptr[b]);
            nest_ptr[a]->current_nest = a;
            nest_ptr[b]->current_nest = b;
        } else {
            int a;
            cin >> a;
            cout << pig[a]->current_nest << '\n';
        }
    }
    return;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
