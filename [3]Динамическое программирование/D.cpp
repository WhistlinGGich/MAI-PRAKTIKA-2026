#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<vector<bool>> dangerous(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        if (x <= n && y <= m) {
            dangerous[x][y] = true;
        }
    }

    int MOD = 1000000007;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (dangerous[i][j]) {
                dp[i][j] = 0;
                continue;
            }
            if (i > 0) {
                dp[i][j] += dp[i - 1][j];
                if (dp[i][j] >= MOD) {
                    dp[i][j] -= MOD;
                }
            }
            if (j > 0) {
                dp[i][j] += dp[i][j - 1];
                if (dp[i][j] >= MOD) {
                    dp[i][j] -= MOD;
                }
            }
        }
    }

    cout << dp[n][m] << "\n";

    return 0;
}