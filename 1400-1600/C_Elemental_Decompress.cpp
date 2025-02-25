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
    vi a(n,0);
    map<int,int>mpp;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mpp[a[i]]++;
    }
    if(mpp[1]>1 || mpp[n]<1){
        cout<<"NO"<<endl; return;
    }
    set<int>miss;
    // vi dble;
    set<int> dble;
    for(int i = 1; i<=n; i++){
        if(!mpp[i])miss.insert(i);
        else if(mpp[i]>2){
            cout<<"NO"<<endl;return;
        }
        else if(mpp[i]==2) {dble.insert(i);}
    }
    set<int>cpyMiss = miss;
    // sort(dble.begin(), dble.end());
    map<int,int> Store;
    for(int i = 1; i<=n; i++)Store[i] = i;
    for(auto x: dble){
        auto it = miss.lower_bound(x);
        if(it==miss.begin()){
            cout<<"NO"<<endl; return;
        }else{
            it--;
            Store[*it] = x;
            Store[x] = *it;
            miss.erase(it);
        }
    }
    cout<<"YES"<<endl;
    vi A(n+1, 0), B(n+1, 0);
    for(int i = 0; i<n; i++){
        auto it = dble.find(a[i]);
        auto it2 = dble.find(-a[i]);
        if(it!=dble.end()){
            A[i] = a[i];
            B[i] = Store[a[i]];
            dble.erase(it);
            dble.insert(-*it);
        }
        else if(it2!=dble.end()){
            A[i] = Store[a[i]];
            B[i] = a[i];
            dble.erase(it2);
        }else{
            A[i] = a[i], B[i] = a[i];
        }
    }
    for(int i = 0; i<n; i++){
        cout<<A[i]<<" ";
    }cout<<endl;
    for(int i = 0; i<n; i++){
        cout<<B[i]<<" ";
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}