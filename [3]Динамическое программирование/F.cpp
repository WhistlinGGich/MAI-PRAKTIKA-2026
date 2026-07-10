#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<long long> dp(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            long long best = dp[i - 1];
            if (i % 2 == 0 && dp[i / 2] < best) {
                best = dp[i / 2];
            }
            if (i % 3 == 0 && dp[i / 3] < best) {
                best = dp[i / 3];
            }
            dp[i] = best + i;
        }
        cout << dp[n] << "\n";
    }

    return 0;
}