#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n , m;
string grid[51];
int xP[] = {0,1,0,-1};
int yP[] = {1,0,-1,0};
bool visited[50][50];
void dfs(int x , int y){
	if(x<0 || y<0 || x>=n || y>=m || visited[x][y])return;
	if(grid[x][y] == '#')return;
	visited[x][y] = true;
	for(int i = 0 ;i<4;i++){
		dfs(x+xP[i] , y+yP[i]);
	}
}
void Solve(){
	cin >> n >> m;
	memset(visited , 0 , sizeof(visited));
	for(int i = 0 ;i<n;i++){
		cin >> grid[i];
	}
	for(int i = 0;i<n;i++){
		for(int j = 0 ;j<m;j++){
			if(grid[i][j] == 'B'){
				for(int k = 0 ; k<4;k++){
					int nX = i+xP[k];
					int nY = j+yP[k];
					if(nX>=0 && nY>=0 && nX<n && nY<m){
						if(grid[nX][nY]=='G'){
							cout << "NO\n";
							return;
						} else if(grid[nX][nY] == '.'){
							grid[nX][nY] = '#';
						}
					}
				}
			}
		}
	}
	dfs(n-1 , m-1);
	for(int i = 0 ;i<n;i++){
		for(int j = 0 ; j<m;j++){
			if(grid[i][j]=='G' && !visited[i][j]){
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
 
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}