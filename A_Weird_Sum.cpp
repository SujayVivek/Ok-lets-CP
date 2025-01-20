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
    int n, m; cin>>n>>m;
    map<int, vi>mpx, mpy;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int x; cin>>x;
            mpx[x].push_back(i);
            mpy[x].push_back(j);
        }
    }
    int S = 0;
    for(auto it: mpx){
        vector<int> v = it.second;
        sort(v.begin(), v.end());
        vi Pref(v.size(),0);
        Pref[0] = v[0];
        int subSum = v[0];
        for(int i = 1; i< v.size(); i++){
            subSum+= v[i];
            Pref[i] = Pref[i-1] + v[i];
        }
        for(int i = 0; i<v.size(); i++){
            if(i>0) S+= v[i]*(i)-Pref[i-1];
            S+= Pref[v.size()-1]-Pref[i]-v[i]*(v.size()-i-1);
        }
    }
    for (auto it : mpy)
    {
        vector<int> v = it.second;
        sort(v.begin(), v.end());
        vi Pref(v.size(), 0);
        Pref[0] = v[0];
        int subSum = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            subSum += v[i];
            Pref[i] = Pref[i - 1] + v[i];
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (i > 0)
                S += v[i] * (i)-Pref[i - 1];
            S += Pref[v.size() - 1] - Pref[i] - v[i] * (v.size() - i - 1);
        }
    }
    cout<<S/2<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}