#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    
    if (n == 0) {
        cout << 10 << "\n";
        return;
    }
    
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    string res = "";
    for (int i = 9; i >= 2; --i) {
        while (n % i == 0) {
            res += to_string(i);
            n /= i;
        }
    }

    if (n > 1) {
        cout << -1 << "\n";
    } else {
        reverse(res.begin(), res.end());
        cout << res << "\n";
    }
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