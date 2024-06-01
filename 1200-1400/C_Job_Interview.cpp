#include <bits/stdc++.h>

using namespace std;

//   _______ _     _                     _        _        __             _   _            _                            
//  |__   __| |   (_)                   | |      (_)      / _|           | | | |          (_)                           
//     | |  | |__  _ ___    ___ ___   __| | ___   _ ___  | |_ ___  _ __  | |_| |__   ___   _ _ __  ___  __ _ _ __   ___ 
//     | |  | '_ \| / __|  / __/ _ \ / _` |/ _ \ | / __| |  _/ _ \| '__| | __| '_ \ / _ \ | | '_ \/ __|/ _` | '_ \ / _ \
//     | |  | | | | \__ \ | |_| (_) | |_| |  __/ | \__ \ | || (_) | |    | |_| | | |  __/ | | | | \__ \ |_| | | | |  __/
//     |_|  |_| |_|_|___/  \___\___/ \__,_|\___| |_|___/ |_| \___/|_|     \__|_| |_|\___| |_|_| |_|___/\__,_|_| |_|\___|

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
#define loopm(ii, i, n, p) for (ll ii = i; ii < n; ii+p)
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define MP make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vi> vvi;

typedef vector<long long> vll;
typedef vector<vll> vvll;

void solve_3(list <int>a , list <int>b, int n, int m){
    auto it = a.begin();
    auto it2= b.begin();
    while(it!=a.end()){
        cout<<*it<<" ";
        it++;
    }cout<<endl;return;
}

ll solve_2(list <int> a, list <int> b, int n,int m){
    ll sum = 0;int i =0;
    auto it1 = a.begin(); auto it2 = b.begin();
    while(n>0 && m>0){
        if(*it1> *it2){
            sum+= *it1; n--; 
        } 
        else if(*it1< *it2){
            sum+= *it2;m--; 
        }
        else{
            if(n<m){
                m--;
                sum+= *it2; 
            }
            else{
                n--; 
                sum+= *it1; 
            }
        }
        it1++; it2++;
    }
    while(n>0){
        sum+= *it1; n--; it1++; it2++;
    }
    while(m>0){
        sum+= *it2; m--; it1++; it2++;
    }
    return sum;
}
void Solve() {
    // Your code for each test case goes here
   int n, m, pdoubt = INT_MAX, tdoubt = INT_MAX, pp = 0, tt = 0;
	cin >> n >> m;
	long long sum = 0, answer = 0;
	int A[n+m+1];
	int B[n+m+1];
	int chooser[n+m+1] = {0};
	for (int i = 0; i<(n+m+1); i++){
		cin >> A[i];
	}
	for (int i = 0; i<(n+m+1); i++){
		cin >> B[i];
	}
 
	for (int i = 0; i<(n+m+1); i++){
		if(A[i]>B[i]){ 
			if (pp<n){
				chooser[i] = 1;
				sum += A[i];
				pp++;
			}else if (pp == n){
				chooser[i] = 2;
				pdoubt = i;
				pp++;
			}else{
				chooser[i] = 2;
				sum += B[i];
				tt++;
			}
		}else{
			if (tt<m){
				chooser[i] = 2;
				sum += B[i];
				tt++;
			}else if (tt==m){
				chooser[i] = 1;
				tdoubt = i;
				tt++;
			}else{
				chooser[i] = 1;
				sum += A[i];
				pp++;
			}
		}
	}
	if (pdoubt<tdoubt){
		for (int i = 0; i<n+m+1; i++){
			if (i<pdoubt && (pdoubt<n+m+1)){
				if (chooser[i]==1){
					answer = sum + ((pdoubt<n+m+1)? A[pdoubt]:0) + ((tdoubt<n+m+1)? A[tdoubt]:0);
					answer = answer - A[i];
				}else{
					answer = sum + ((pdoubt<n+m+1)? B[pdoubt]:0) + ((tdoubt<n+m+1)? B[tdoubt]:0);
					answer = answer - B[i];
				}
			}else if (i<tdoubt && tdoubt<(n+m+1)){
				if (chooser[i]==1){
					answer = sum + ((pdoubt<n+m+1)? B[pdoubt]:0) + ((tdoubt<n+m+1)? A[tdoubt]:0);
					answer = answer - A[i];
				}else{
					answer = sum + ((pdoubt<n+m+1)? B[pdoubt]:0) + ((tdoubt<n+m+1)? B[tdoubt]:0);
					answer = answer - B[i];
				}
			}else{
				answer = sum + ((pdoubt<n+m+1)? B[pdoubt]:0) + ((tdoubt<n+m+1)? A[tdoubt]:0);
				if (chooser[i]==1){
					answer = answer - A[i];
				}else{
					answer = answer - B[i];
				}
			}
			cout << answer << " ";
		}
	}else{
		for (int i = 0; i<n+m+1; i++){
			if (i<tdoubt && tdoubt<(n+m+1)){
				if (chooser[i]==2){
					answer = sum + ((pdoubt<n+m+1)? B[pdoubt]:0) + ((tdoubt<n+m+1)? B[tdoubt]:0);
					answer = answer - B[i];
				}else{
					answer = sum + ((pdoubt<n+m+1)? A[pdoubt]:0) + ((tdoubt<n+m+1)? A[tdoubt]:0);
					answer = answer - A[i];
				}
			}else if (i<pdoubt && (pdoubt<n+m+1)){
				if (chooser[i]==1){
					answer = sum + ((pdoubt<n+m+1)? A[pdoubt]:0) + ((tdoubt<n+m+1)? A[tdoubt]:0);
					answer = answer - A[i];
				}else{
					answer = sum + ((pdoubt<n+m+1)? B[pdoubt]:0) + ((tdoubt<n+m+1)? A[tdoubt]:0);
					answer = answer - B[i];
				}
			}else{
				answer = sum + ((pdoubt<n+m+1)? B[pdoubt]:0) + ((tdoubt<n+m+1)? A[tdoubt]:0);
				if (chooser[i]==1){
					answer = answer - A[i];
				}else{
					answer = answer - B[i];
				}
			}
			cout << answer << " ";
		}
	}
	cout << '\n';

}

int32_t main() {
    auto begin = chrono::high_resolution_clock::now(); // Initialize the begin time measurement

    fastio();
    // #ifndef ONLINE_JUDGE
    //     freopen("error.txt", "w", stderr);
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }

    // auto end = chrono::high_resolution_clock::now();
    // auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
