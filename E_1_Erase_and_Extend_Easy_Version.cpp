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
    int n, k;cin>>n>>k;
    string s;cin>>s;
    char c = s[0];
    int i = 0;
    string new_string = s;
    bool oked = 0;
    for(i = 1; i<n; i++){
        if(s[i]>c){
            new_string = s.substr(0,i);
            break;
        }
        else if(s[i]==c){
            string a1 = s.substr(0,i);
            
            a1+=a1;
            string a2 = s.substr(0,2*i);
            // cout<<"A2="<<a2<<endl;
            // cout<<"A1="<<a1<<endl;
            a1+='{', a2+='{';
            if(a1<a2){
                // cout<<"HI"<<endl;
                new_string = a1.substr(0,a1.length()-1);
                oked = true;
                break;
            }
        }
    }
    if(oked){
        for(int j = i;j<new_string.length(); j++){
            if(new_string[j]<s[j]){
                new_string = new_string.substr(0,i+j);
            }
        }
    }
    
    int p = new_string.length();
    if(k<p){
        cout<<new_string.substr(0,k);
        return;
    }
    int r = (k%p)? k/p: k/p+1;
    for(int j = 0; j<k/p; j++){
        cout<<new_string;
    }

    cout<<new_string.substr(0,k%p)<<endl;
    return;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}