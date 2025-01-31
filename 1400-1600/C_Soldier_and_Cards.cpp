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
    int n;  cin>>n;
    map<pair<queue<int>,queue<int>>, int>mpp;
    int A; cin>>A;
    queue<int> q1, q2;
    // int num1 = 0, num2 = 0;
    for(int i = 0; i<A; i++){
        int c; cin>>c;
        q1.push(c);
        // num1|= 1<<c;
    }
    int B; cin>>B;
    for(int i = 0; i<B; i++){
        int c; cin>>c;
        q2.push(c);
        // num2|= 1<<c;
    }
    int fights = 0;
    // mpp[{q2,q1}]++, mpp[{q1,q2}]++;
    while(!q1.empty() && !q2.empty()){
        if (mpp[{q1, q2}] || mpp[{q2, q1}])
        {
            // cout<<fights<<" Hi"<<endl;
            cout << "-1" << endl;
            exit(0);
        }
        mpp[{q1, q2}]++, mpp[{q2, q1}]++;
        int ff = q1.front(), ss = q2.front();
        // cout<<ff<<" hi "<<ss<<endl;
        fights++;
        if(ff>ss){
            // num2^= 1<<ss;
            // num1|= 1<<ss;
            q1.pop(), q2.pop();
            q1.push(ss), q1.push(ff);
        }else{
            // num1^= 1<<ff;
            // num2|= 1<<ff;
            q1.pop(), q2.pop();
            q2.push(ff), q2.push(ss);
        }
    }
    cout<<fights<<" ";
    if(q1.empty())cout<<2<<endl;
    else cout<<1<<endl;
}


int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}