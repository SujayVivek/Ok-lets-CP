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
    int r, c, k;
    cin >> r >> c >> k;

    int cnt = 0;
    vector<vector<char>> grid(r, vector<char>(c));
    
    // Input the grid and count total 'R'
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'R') {
                cnt++;
            }
        }
    }

    // Calculate per chicken group and remainder
    int per_chicken = cnt / k;
    int rem_chicken = cnt % k;

    // Prepare the alphabets vector
    vector<char> alphabets;
    for (int i = 48; i <= 122; i++) {
        if ((i > 57 && i < 65) || (i > 90 && i < 97)) continue;
        alphabets.push_back((char)i);
    }

    // Ensure k doesn't exceed the number of available characters
    if (k > alphabets.size()) {
        cout << "Too many groups for available characters!" << endl;
        return;
    }

    // Assign groups to the grid
    int l = 0; // Index for alphabets
    int current_chickens = 0; // Chickens assigned to the current group

    for (int i = 0; i < r; i++) {
        // Determine traversal direction (left-to-right or right-to-left)
        if (i % 2 == 0) { // Left-to-right
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 'R') current_chickens++;

                // Assign current cell to the current group
                grid[i][j] = alphabets[l];

                // Check if current group is complete
                if (current_chickens == per_chicken + (rem_chicken > 0 ? 1 : 0)) {
                    current_chickens = 0;
                    rem_chicken--;
                    if (l + 1 < k) l++; // Move to the next group
                }
            }
        } else { // Right-to-left
            for (int j = c - 1; j >= 0; j--) {
                if (grid[i][j] == 'R') current_chickens++;

                // Assign current cell to the current group
                grid[i][j] = alphabets[l];

                // Check if current group is complete
                if (current_chickens == per_chicken + (rem_chicken > 0 ? 1 : 0)) {
                    current_chickens = 0;
                    rem_chicken--;
                    if (l + 1 < k) l++; // Move to the next group
                }
            }
        }
    }

    // Output the updated grid
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
