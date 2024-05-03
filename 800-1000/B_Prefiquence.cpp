
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
    	int n,m; string a,b;
    	cin >> n >> m >> a >> b;
    	int cnt = 0, cnt2 = 0;
        while (cnt < n and cnt2 < m)
        {
            if (a[cnt] == b[cnt2]) cnt++;
            cnt2++;
        }
        cout << cnt << endl;
    }
    return 0;
}

