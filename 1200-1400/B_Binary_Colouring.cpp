#include <bits/stdc++.h>

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
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

void Solve(){
    long long x;
	cin >> x;
	long long siz = 0;
	vector <int> bin(32, 0);
	int i = 0;
	while(x>0){
		bin[i++] = x%2;
		x /= 2;
	}
	for (int i = 0; i<31; i++){
		if (bin[i]==1 && bin[i+1]==1){
			bin[i] = -1;
			bin[i+1] = 0;
			
			int k = i+2;
			while(bin[k]==1){
				bin[k] = 0;
				k++;
			}
			bin[k] = 1;
		}
	}
	for (int i =0; i<32; i++) if (bin[i]!=0) siz = i;
	cout << ++siz << '\n';
	for (int i = 0; i<siz; i++) cout << bin[i] << ' ';
	cout << '\n';
}   

int main() {
    auto begin = chrono::high_resolution_clock::now(); // Initialize the begin time measurement

    fastio();
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
