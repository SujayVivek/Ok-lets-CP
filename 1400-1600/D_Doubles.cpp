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
    int n; cin>>n;
    vector<pair<int,int>> vp;
    map<pair<int,int>, map<int,int>> mpp;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        map<int,int> sub;
        for(int j = 0; j < x; j++){
            int num; cin >> num;
            sub[num]++;
        }
        mpp[{x, i+1}] = sub;
        vp.push_back({x, i+1});
    }

    double Ans = 0;
    for(int i = 0; i < vp.size() - 1; i++){
        double subAns = 0;
        for(int j = i+1; j < vp.size(); j++){
            int SZ1 = vp[i].first, SZ2 = vp[j].first;
            double ANZ = 0;
            map<int,int> sub1 = mpp[vp[i]], sub2 = mpp[vp[j]];

            if(sub1.size() <= sub2.size()){
                for(auto it: sub1){
                    double prob1 = (double)it.second / SZ1;
                    double prob2 = sub2.count(it.first) ? (double)sub2[it.first] / SZ2 : 0;
                    ANZ+= prob1*prob2;
                }
            } else {
                for(auto it: sub2){
                    double prob1 = (double)it.second / SZ2;
                    double prob2 = sub1.count(it.first) ? (double)sub1[it.first] / SZ1 : 0;
                    ANZ+= prob1*prob2;
                }
            }
            subAns = max(subAns, ANZ);
        }
        Ans = max(Ans, subAns);
    }
    
    cout << fixed << setprecision(15) << Ans << endl;
}

int32_t main() {
    int tt_ = 1;
    while (tt_--) {
        Solve();
    }
    return 0;
}
