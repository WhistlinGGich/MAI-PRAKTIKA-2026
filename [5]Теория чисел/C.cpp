#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    long long mod = 1000000007;
    long long fact = 1;
    
    for (long long i = 1; i <= n - 1; ++i) {
        fact = (fact * i) % mod;
    }

    long long inv2 = 500000004;
    long long ans = (fact * inv2) % mod;

    cout << ans << "\n";

    return 0;
}