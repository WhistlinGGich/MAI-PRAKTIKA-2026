#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    long long sum = 0;
    long long MOD = 1000000007;

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        sum = (sum + a) % MOD;
    }

    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long power = 1;
    long long base = 2;
    int exp = n - 1;

    while (exp > 0) {
        if (exp % 2 == 1) {
            power = (power * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }

    long long ans = (sum * power) % MOD;
    ans = (ans + MOD) % MOD;

    cout << ans << "\n";

    return 0;
}