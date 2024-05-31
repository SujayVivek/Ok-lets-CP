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

void solve(){
	int n, m, pdoubt = 1e9, tdoubt = 1e9, pcount = 0, tcount = 0;
	cin >> n >> m;
	long long sum = 0, answer = 0;
	int A[n+m+1];
	int B[n+m+1];
	int role[n+m+1] = {0};
	for (int i = 0; i<(n+m+1); i++){
		cin >> A[i];
	}
	for (int i = 0; i<(n+m+1); i++){
		cin >> B[i];
	}
 
	for (int i = 0; i<(n+m+1); i++){
		if(A[i]>B[i]){ // ideally programmer
			if (pcount<n){
				role[i] = 1;
				sum += A[i];
				pcount++;
			}else if (pcount == n){
				role[i] = 2;
				pdoubt = i;
				pcount++;
			}else{
				role[i] = 2;
				sum += B[i];
				tcount++;
			}
		}else{
			if (tcount<m){
				role[i] = 2;
				sum += B[i];
				tcount++;
			}else if (tcount==m){
				role[i] = 1;
				tdoubt = i;
				tcount++;
			}else{
				role[i] = 1;
				sum += A[i];
				pcount++;
			}
		}
	}
	if (pdoubt<tdoubt){
		for (int i = 0; i<n+m+1; i++){
			if (i<pdoubt && (pdoubt<n+m+1)){
				if (role[i]==1){
					answer = sum + ((pdoubt<n+m+1)? A[pdoubt]:0) + ((tdoubt<n+m+1)? A[tdoubt]:0);
					answer = answer - A[i];
				}else{
					answer = sum + ((pdoubt<n+m+1)? B[pdoubt]:0) + ((tdoubt<n+m+1)? B[tdoubt]:0);
					answer = answer - B[i];
				}
			}else if (i<tdoubt && tdoubt<(n+m+1)){
				if (role[i]==1){
					answer = sum + ((pdoubt<n+m+1)? B[pdoubt]:0) + ((tdoubt<n+m+1)? A[tdoubt]:0);
					answer = answer - A[i];
				}else{
					answer = sum + ((pdoubt<n+m+1)? B[pdoubt]:0) + ((tdoubt<n+m+1)? B[tdoubt]:0);
					answer = answer - B[i];
				}
			}else{
				answer = sum + ((pdoubt<n+m+1)? B[pdoubt]:0) + ((tdoubt<n+m+1)? A[tdoubt]:0);
				if (role[i]==1){
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
				if (role[i]==2){
					answer = sum + ((pdoubt<n+m+1)? B[pdoubt]:0) + ((tdoubt<n+m+1)? B[tdoubt]:0);
					answer = answer - B[i];
				}else{
					answer = sum + ((pdoubt<n+m+1)? A[pdoubt]:0) + ((tdoubt<n+m+1)? A[tdoubt]:0);
					answer = answer - A[i];
				}
			}else if (i<pdoubt && (pdoubt<n+m+1)){
				if (role[i]==1){
					answer = sum + ((pdoubt<n+m+1)? A[pdoubt]:0) + ((tdoubt<n+m+1)? A[tdoubt]:0);
					answer = answer - A[i];
				}else{
					answer = sum + ((pdoubt<n+m+1)? B[pdoubt]:0) + ((tdoubt<n+m+1)? A[tdoubt]:0);
					answer = answer - B[i];
				}
			}else{
				answer = sum + ((pdoubt<n+m+1)? B[pdoubt]:0) + ((tdoubt<n+m+1)? A[tdoubt]:0);
				if (role[i]==1){
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
 
