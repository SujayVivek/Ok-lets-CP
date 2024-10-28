#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<ll> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    int curr_pos = 0;  
    int k = 1;         
    ll total_cost = 0;
    
    while(curr_pos < n) {  
        if(k > m) {  
            cout << -1 << "\n";
            return;
        }
                ll sum = 0;
        int new_pos = curr_pos;
        
        while(new_pos < n && sum + a[new_pos] <= b[k-1]) {
            sum += a[new_pos];
            new_pos++;
        }
        
        if(new_pos > curr_pos) {  // If we can remove some elements
            total_cost += m - k;   // Add cost of Type 2 operation
            curr_pos = new_pos;    // Update position
        } else if(k < m) {        // If we can't remove elements and k < m
            k++;                   // Use Type 1 operation (free)
        } else {                  // If we can't do either operation
            cout << -1 << "\n";
            return;
        }
    }
    
    cout << total_cost << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}