#include <iostream>

using namespace std;

bool check(long long v, long long cnt1, long long cnt2, long long x, long long y) {
    long long not_x = v - v / x;
    long long not_y = v - v / y;
    long long not_both = v - v / (x * y);
    
    return not_x >= cnt1 && not_y >= cnt2 && not_both >= (cnt1 + cnt2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long cnt1, cnt2, x, y;
    if (cin >> cnt1 >> cnt2 >> x >> y) {
        long long left = 1, right = 20000000000LL;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(mid, cnt1, cnt2, x, y)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}