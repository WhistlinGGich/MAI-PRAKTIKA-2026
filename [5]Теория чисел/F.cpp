#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> count(8, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        count[a]++;
    }

    if (count[5] > 0 || count[7] > 0) {
        cout << -1 << "\n";
        return 0;
    }

    int t124 = count[4];
    int t136 = count[3];
    int t126 = count[2] - count[4];

    if (t124 < 0 || t136 < 0 || t126 < 0 ||
        count[1] != n / 3 ||
        t124 + t136 + t126 != n / 3 ||
        count[6] != t136 + t126) {
        cout << -1 << "\n";
        return 0;
    }

    for (int i = 0; i < t124; ++i) {
        cout << "1 2 4\n";
    }
    for (int i = 0; i < t136; ++i) {
        cout << "1 3 6\n";
    }
    for (int i = 0; i < t126; ++i) {
        cout << "1 2 6\n";
    }

    return 0;
}