#include <bits/stdc++.h>

using namespace std;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
#define loop(ii, i, n) for (ll ii = i; ii < n; ++ii)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<vi> vvi;

void Solve() {
    int n, m;
    cin >> n >> m;
    
    map<vi, int> mapp;
    map<vi, int> mapp2;
    vvi a(n, vi(m));
    vvi b(n, vi(m));
    
    // Read matrix a and populate mapp with sorted rows
    loop(i, 0, n) {
        vi row(m);
        loop(j, 0, m) {
            cin >> a[i][j];
            row[j] = a[i][j];
        }
        sort(all(row));
        mapp[row]++;
        // clear(row);
        row.clear();
    }
    
    // Read matrix b and check against mapp
    loop(i, 0, n) {
        vi row(m);
        loop(j, 0, m) {
            cin >> b[i][j];
            row[j] = b[i][j];
        }
        if(m>1){
            sort(all(row));
        if (mapp[row] == 0) {
            cout << "NO" << endl; row.clear();a.clear(); b.clear();  mapp2.clear();mapp.clear();
            return;
        }
        mapp[row]--;
        }
        // row.erase();
        row.clear();
        
    }
    
    // Check columns of matrix a and b
    if (n > 1) {
        loop(i, 0, m) {
            vi colA(n);
            loop(j, 0, n) {
                colA[j] = a[j][i];
            }
            sort(all(colA));
            mapp2[colA]++;
            colA.clear();
        }

        loop(i, 0, m) {
            vi colB(n);
            loop(j, 0, n) {
                colB[j] = b[j][i];
            }
            sort(all(colB));
            if (mapp2[colB] == 0) {
                cout << "NO" << endl; colB.clear(); a.clear(); b.clear();  mapp2.clear();mapp.clear();
                return;
            }
            mapp2[colB]--;
            colB.clear();
        }
    }

    cout << "YES" << endl;
    a.clear(); b.clear(); mapp2.clear();mapp.clear();
}

int32_t main() {
    fastio();
    
    int tt_;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }

    return 0;
}
