#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

class DSU {
    vi parent, rank;
    int components;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        components = n;
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
        components--;
        return true;
    }
    
    int getComponents() { return components; }
};

void Solve() {
    int n, m;
    cin >> n >> m;
    
    // Read cables
    vector<pair<int,int>> cables(m);
    for(int i = 0; i < m; i++) {
        cin >> cables[i].ff >> cables[i].ss;
        cables[i].ff--; // Convert to 0-based indexing
        cables[i].ss--;
    }
    
    // Find extra cables using DSU
    DSU dsu(n);
    vector<tuple<int,int,int>> extra_cables; // (cable_idx, u, v)
    for(int i = 0; i < m; i++) {
        if(!dsu.unite(cables[i].ff, cables[i].ss)) {
            extra_cables.push_back({i, cables[i].ff, cables[i].ss});
        }
    }
    
    // If not enough extra cables
    if(extra_cables.size() < dsu.getComponents() - 1) {
        cout << -1 << endl;
        return;
    }
    
    // Map components to their nodes
    vector<int> comp_id(n);
    vector<vector<int>> components(n);
    for(int i = 0; i < n; i++) {
        int root = dsu.find(i);
        comp_id[i] = root;
        components[root].push_back(i);
    }
    
    // Get unique components
    set<int> unique_comps;
    for(int i = 0; i < n; i++) {
        if(!components[i].empty()) {
            unique_comps.insert(i);
        }
    }
    
    // Generate operations
    vector<pair<int,int>> operations; // (cable_idx, new_endpoint)
    int base_comp = *unique_comps.begin();
    
    for(auto comp : unique_comps) {
        if(comp == base_comp) continue;
        
        if(extra_cables.empty()) {
            cout << -1 << endl;
            return;
        }
        
        auto [cable_idx, u, v] = extra_cables.back();
        extra_cables.pop_back();
        
        // Connect to base component
        int new_endpoint = components[base_comp][0];
        operations.push_back({cable_idx + 1, new_endpoint + 1}); // Convert back to 1-based
    }
    
    // Output result
    cout << operations.size() << endl;
    int i = 1;
    for(auto [cable, endpoint] : operations) {
        cout << i<<" "<<cable << " " << endpoint << endl;
        i++;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tt_ = 1;
    // cin >> tt_;
    while(tt_--) {
        Solve();
    }
    return 0;
}