#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int count_up = 0;
        for (char c : s) {
            if (c == 'U') {
                count_up++;
            }
        }

        // If count_up is odd, Alice will win.
        if (count_up % 2 == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}