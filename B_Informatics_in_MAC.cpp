#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int MEX(vi a){
    int mex = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i<a.size(); i++){
        if(a[i]==mex){
            mex++;
        }else if(a[i]>mex){
            break;
        }
    }
    return mex;
}
void Solve() {
    int n; cin>>n;
    vi a(n,0);
    vi zero_pos;
    int mx_ele = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(!a[i])zero_pos.push_back(i);
        mx_ele = max(mx_ele, a[i]);
    }
    if(zero_pos.size()==0){
        cout<<n<<endl;
        for(int i = 1; i<=n; i++){
            cout<<i<<" "<<i<<endl;
        }
        return;
    }else{
        int mex = MEX(a);
        // cout<<"HI "<<mex<<endl;
        set<int>st;
        int i = 0;
        while(i<n){
            if(a[i]<mex){
                st.insert(a[i]); 
            }
            i++;
            if(st.size() == mex) break;
        }int j = i;
        // cout<<"j= "<<j<<endl;
        st.clear();
        while(i<n){
            if(a[i]<mex)
                st.insert(a[i]);
            i++;
        }
        if(st.size()==mex){
            cout<<2<<endl;
            cout<<1<<" "<<j<<endl;
            cout<<j+1<<" "<<n<<endl;
        }else{
            cout<<-1<<endl;
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