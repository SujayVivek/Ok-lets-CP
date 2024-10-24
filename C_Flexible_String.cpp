#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
#define endl "\n"
#define pb push_back
#define MP make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;

void Solve() {
    ll n, k;cin>>n>>k;
    string a ,b;cin>>a>>b;
    map<char,ll>mpp;
    set<char>st;
    ll i = 0, j = 0;
    ll mxLen = 0,Len = 0;
    string copy_s = a, new_s;
    if(k!=0)
    while(i<n && j<n){
        if(st.size()>k){
            j--;
            mpp[j]--;
            Len--;
            if(mpp[j]==0){
                auto it = st.erase(a[j]);
            }
            copy_s[j] = a[j];
            if(Len>=mxLen){
                new_s = copy_s;
                mxLen = Len;
            }
            if(a[i]==b[i]){
                Len--;
            }else{
                mpp[a[i]]--;
                Len--;
            }

            if(mpp[a[i]]==0){
                auto it = st.erase(a[i]);
            }
            i++;
            copy_s[i] = a[i];
        }
        if(a[j]==b[j]){
            j++;
            Len++;
            continue;
        }else{
            if(mpp[a[j]]){
                copy_s[j] = b[j]; 
            }else{
                st.insert(a[j]);
                mpp[a[j]]++;
                copy_s[j] = b[j];
            }
            Len++;
            j++;
        }
    }
    if(st.size()>k){
        j--;
        copy_s[j] = a[j]; Len--; 
    }
    if(Len>mxLen){
        new_s = copy_s;
        mxLen = Len;
    }
    ll l = 0;int ans = 0;
    // cout<<new_s<<" "<<"HI"<<endl;
    for(int i = 0; i<n; i++){
        if(new_s[i]==b[i]){
            l++; 
        }else{
            ans+= l*(l+1)/2;
            l = 0;
        }
    }
    ans+= l*(l+1)/2;

    cout<<ans<<endl;return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}