#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

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

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'a']++;
    }

    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans = (ans * i) % MOD;
    }

    for (int i = 0; i < 26; ++i) {
        if (count[i] > 1) {
            long long fact = 1;
            for (int j = 1; j <= count[i]; ++j) {
                fact = (fact * j) % MOD;
            }
            ans = (ans * modInverse(fact)) % MOD;
        }
    }

    cout << ans << "\n";

    return 0;
}