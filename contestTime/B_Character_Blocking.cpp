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
    string s1, s2;
     cin>>s1>>s2;
     int n =s1.length();
     set<int> uneq;
     for(int i = 0; i<n; i++){
        if(s1[i]!=s2[i]) uneq.insert(i);
     }
     vvi Lvi;
     int T, Q; cin>>T>>Q;
     set<int> Blocked;
     while (Q--) {
        int num;
        cin >> num;
        if (num == 1) {
            int pos;
            cin >> pos;
            Lvi.push_back({1, pos-1}); // Use push_back for insertion
        } else if (num == 2) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            Lvi.push_back({2, a, b-1, c, d-1});
        } else if (num == 3) {
            Lvi.push_back({3});
        }
    }

    for (int i = 0; i < Lvi.size(); i++) {
        if (Lvi[i][0] == 1) {
            if (i + T < Lvi.size()) {
                Lvi.insert(Lvi.begin() + i + T, {5, Lvi[i][1]}); // Properly insert in vector
            }
        }
    }
    for(int i = 0; i<Lvi.size(); i++){
        if(Lvi[i][0] == 1){
            auto it = uneq.find(Lvi[i][1]);
            if(it!=uneq.end()){ uneq.erase(it); Blocked.insert(*it);}

        }else if(Lvi[i][0] == 2){
            auto it1 = uneq.find(Lvi[i][2]);
            auto it2 = uneq.find(Lvi[i][4]);
            if(it1!=uneq.end()) uneq.erase(*it1);
            if(it2!=uneq.end()) uneq.erase(*it2);
            if(Lvi[i][1]==1){
                char Temp = s1[Lvi[i][2]];
                if(Lvi[i][3] == 1){
                    s1[Lvi[i][2]] = s1[Lvi[i][4]];
                    s1[Lvi[i][4]] = Temp;
                }else{
                    s1[Lvi[i][2]] = s2[Lvi[i][4]];
                    s2[Lvi[i][4]] = Temp;
                }
            }
            else{
                char Temp = s2[Lvi[i][2]];
                if(Lvi[i][3] == 1){
                    s2[Lvi[i][2]] = s1[Lvi[i][4]];
                    s1[Lvi[i][4]] = Temp;
                }else{
                    s2[Lvi[i][2]] = s2[Lvi[i][4]];
                    s2[Lvi[i][4]] = Temp;
                }
            }
            if(s1[Lvi[i][2]]!=s2[Lvi[i][2]] && Blocked.find(Lvi[i][2])==Blocked.end())uneq.insert(Lvi[i][2]);
            if(s1[Lvi[i][4]]!=s2[Lvi[i][4]] && Blocked.find(Lvi[i][4])==Blocked.end())uneq.insert(Lvi[i][4]);
        }else if(Lvi[i][0] == 3){
            if(uneq.empty()) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else if(Lvi[i][0] == 5){
            if(s1[Lvi[i][1]]!=s2[Lvi[i][1]]){
                uneq.insert(Lvi[i][1]); 
                auto it = Blocked.find(Lvi[i][1]);
                if(it!=Blocked.end()) Blocked.erase(it);
            }
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