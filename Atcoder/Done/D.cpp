#include <bits/stdc++.h>
using namespace std;
#define int long long

// Function to generate primes up to a given limit
vector<int> generate_primes(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}

void Solve() {
    int N;
    cin >> N;

    // Step 1: Generate primes for p^8 and p^2 * q^2
    int limit_p8 = pow(N, 1.0 / 8) + 1; // For p^8
    int limit_p2 = sqrt(N) + 1;         // For p^2 * q^2

    vector<int> primes_p8 = generate_primes(limit_p8);
    vector<int> primes_p2 = generate_primes(limit_p2);

    // Step 2: Count numbers of the form p^8
    int count = 0;
    for (int p : primes_p8) {
        if (pow(p, 8) <= N) count++;
    }

    // Step 3: Count numbers of the form p^2 * q^2
    int m = primes_p2.size();
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (primes_p2[i] * primes_p2[i] * primes_p2[j] * primes_p2[j] <= N) {
                count++;
            } else {
                break; // Stop inner loop early
            }
        }
    }

    cout << count << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solve();
    return 0;
}
