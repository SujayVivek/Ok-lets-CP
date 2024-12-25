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
    vi A; int ok = 0;
    int num = 0;
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        if(x!=1 && x!=-1) {ok = i; num = x; continue;}
        A.push_back(x);
    }
    int maxA=0, minA=0, maxB=0, minB=0;
    int sum = 0, prev = 0; int MAXA = 0, MAXB = 0, MINA = 0, MINB = 0;
    set<int> st; st.clear();
    st.insert(0);
    st.insert(num);
    for(int i = ok-1; i>=0; i--){
        sum+= A[i];
        if(sum>prev) maxA = max(maxA, sum-((MINA<0)?MINA:0));
        else if(sum<prev) minA = min(minA, sum-((MAXA>0)?MAXA:0));
        // cout<<sum<<" minA="<<minA<<" maxA="<<maxA<<endl;
        MAXA = max(MAXA, sum);
        MINA = min(MINA, sum);
        prev = sum;
        st.insert(sum+num);
    } sum = 0, prev = 0;
    for(int i = ok; i<A.size(); i++){
        sum+= A[i];
        if(sum>prev) maxB = max(maxB, sum-((MINB<0)?MINB:0));
        else if(sum<prev) minB = min(minB, sum-((MAXB>0)?MAXB:0));
        MAXB = max(MAXB, sum);
        MINB = min(MINB, sum);
        prev = sum;
        st.insert(sum+num);
    }
    // cout<<maxA<<" hi "<<maxB<<endl;
    for(int i= 0; i<=max(maxB, maxA); i++) st.insert(i);
    for(int i= -1; i>=min(minA, minB); i--) st.insert(i);
    for(int i = num+1; i<=(num+MAXA+MAXB); i++) st.insert(i);
    for(int i = num-1; i>=(num+MINA+MINB); i--)st.insert(i);
    cout<<st.size()<<endl;
    for(auto it: st)cout<<it<<" ";
    cout<<endl;
    return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}