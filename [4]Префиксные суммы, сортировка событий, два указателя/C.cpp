#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        long long current_sum = 0;
        long long max_sum = 0;
        int current_start = 1;
        int best_start = -1;
        int best_end = -1;

        for (int i = 1; i <= n; ++i) {
            long long a;
            cin >> a;

            if (current_sum < 0) {
                current_sum = 0;
                current_start = i;
            }

            current_sum += a;

            if (current_sum > max_sum) {
                max_sum = current_sum;
                best_start = current_start;
                best_end = i;
            }
        }

        if (max_sum > 0 && best_start != -1) {
            cout << best_start << " " << (best_end + 1) << "\n";
        } else {
            cout << "-1 -1\n";
        }
    }

    return 0;
}