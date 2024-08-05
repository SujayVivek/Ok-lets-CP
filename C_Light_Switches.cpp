#include <bits/stdc++.h>
using namespace std;

#define loop(i, start, end) for(int i = start; i < end; i++)
#define vi vector<int>
#define MP make_pair

void Solve() {
    int n, k;
    cin >> n >> k;
    // vll v(n, 0);
    // map<int, int> mpp;
    multiset<pair<long long, int>> st;

    loop(i, 0, n) {
        long long l;cin>>l;
        st.insert(MP(l, 1));
    }
    long long pp = 0;
    long long s = 0;
    while (!st.empty()) {
        auto it = st.begin();
        // cout<< it->first<< " "<<it->second<<endl;
        if (pp >= 2*k*n) {
            cout << -1 << endl;
            return;
        }
        
        if (it->second == 1) {
            st.insert(MP(it->first + k, -1));
            // mpp[it->first]++;
        } else if (it->second == -1) {
            st.insert(MP(it->first + k, 1));
            // mpp[it->first]--;
        }
        
        s += it->second;
        if (s == n) {
            cout << it->first  << endl;
            return;
        }
        
        st.erase(it);
        pp++;
    }

    cout << -1 << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
