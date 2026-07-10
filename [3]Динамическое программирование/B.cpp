#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m;
    if (!(cin >> n >> k >> m)) return 0;

    vector<bool> dangerous(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        dangerous[a] = true;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    long long current_sum = 0;
    long long MOD = 1000000007;

    for (int i = 1; i <= n; ++i) {
        current_sum = (current_sum + dp[i - 1]) % MOD;
        if (i - k - 1 >= 0) {
            current_sum = (current_sum - dp[i - k - 1] + MOD) % MOD;
        }
        if (dangerous[i]) {
            dp[i] = 0;
        } else {
            dp[i] = current_sum;
        }
    }

    cout << dp[n] << "\n";

    return 0;
}