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
    int n, m, k; cin>>n>>m>>k;
    stack<int> Fin;
    queue<int> Init;
    for(int i = 1; i<=k; i++){
        Fin.push(i);
        int x; cin>>x;
        Init.push(x);
    }
    // cout<<"HI "<<Init.front()<<endl;
    set<int> freedom;
    bool ok = true;
    while(!Init.empty()){
        int Tp = Init.front();
        Init.pop();
        freedom.insert(Tp);
        if(freedom.size()>=(n*m)-3) {ok = false;break;}
    }
    if(ok || Init.empty()){
        cout<<"YA"<<endl;return;
    } ok = true;
    while(!Fin.empty()){
        int Tp = Fin.top(); Fin.pop();
        auto it = freedom.find(Tp);
        if(it==freedom.end()){
            cout<<"TIDAK"<<endl;return;
        }else{
            freedom.erase(*it);
        }
        if(!Init.empty()){
            int TP = Init.front();
            Init.pop();
            freedom.insert(TP);
        }
        if(Init.empty()){
            cout<<"YA"<<endl;return;
        }
    }
    cout<<"YA"<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}