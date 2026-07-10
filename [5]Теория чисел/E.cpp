#include <iostream>

using namespace std;

const long long MOD = 1000000007;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    long long b1, q, n;
    cin >> b1 >> q >> n;

    if (n == 0 || b1 == 0) {
        cout << 0 << "\n";
        return;
    }

    if (q == 1 || q == 0) {
        if (q == 1) {
            cout << (b1 % MOD * (n % MOD)) % MOD << "\n";
        } else {
            cout << b1 % MOD << "\n";
        }
        return;
    }

    long long num = (power(q, n) - 1 + MOD) % MOD;
    long long den = power((q - 1 + MOD) % MOD, MOD - 2);
    long long sum = (num * den) % MOD;
    sum = (sum * (b1 % MOD)) % MOD;

    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}