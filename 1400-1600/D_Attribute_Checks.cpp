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

int check(int mid, int m, vi &r){
    int posSc = mid;
    int negSc = m-mid;
    int score = 0;
    int n = r.size();
    for(int i = n-1; i>=0; i--){
        if(r[i]==0){
            if(i!=n-1 && r[i+1]>0){
                posSc--;
            }
            if(i!=n-1 && r[i+1]<0){
                negSc--;
            }
        }else{
            if(r[i]>0){
                if(posSc>=r[i]) score++;
            }else{
                if(negSc>=abs(r[i])) score++;
            }
        }
    }
    return score;
}
void Solve() {
    int n, m;cin>>n>>m;
    vi r(n,0);
    int posSc = 0, negSc = 0;
    int posCart = 0, negCart = 0;
    for(int i = 0; i<n ; i++){
        cin>>r[i];
        if(r[i] == '0'){
            posCart++; negCart++;
        }else if(r[i]>0){
            if(posCart>=abs(r[i]))posSc++;
        }else if(r[i]<0){
            if(negCart>=abs(r[i]))negSc++;
        }
    }
    int mx = max(posSc, negSc);
    int lo = mx;
    int hi = m;
    int ans = 0;
    if(posSc>=negSc){
        //to increase lets move up, and to decrease lets move down
        while(lo<hi){
            int mid = (lo + hi)/2;
            if(check(mid, m, r)>=mx){
                lo = mid;
                ans = mid;
            }else{
                hi = mid -1;
            }
        }
    }else{
        int mid = (lo + hi)/2;
            if(check(mid, m, r)>=mx){
                hi = mid;
                ans = mid;
            }else{
                lo = mid+1;
            }
    }
    cout<<ans<<endl;return;
    
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}