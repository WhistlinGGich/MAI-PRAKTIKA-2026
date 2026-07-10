#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r;
    if (!(cin >> l >> r)) return 0;

    int MOD = 1000000007;
    vector<int> dp(r + 1, 0);
    dp[1] = 1;

    for (int i = 1; i <= r; ++i) {
        if (dp[i] == 0) continue;
        for (int j = i + i; j <= r; j += i) {
            dp[j] += dp[i];
            if (dp[j] >= MOD) {
                dp[j] -= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = l; i <= r; ++i) {
        ans += dp[i];
        if (ans >= MOD) {
            ans -= MOD;
        }
    }

    cout << ans << "\n";

    return 0;
}