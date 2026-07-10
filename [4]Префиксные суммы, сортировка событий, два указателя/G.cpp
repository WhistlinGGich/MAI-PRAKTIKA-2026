#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> count_b(101, 0);
    for (int i = 0; i < m; ++i) {
        int b_val;
        cin >> b_val;
        count_b[b_val]++;
    }

    if (n < m) {
        cout << 0 << "\n\n";
        return 0;
    }

    vector<int> count_a(101, 0);
    for (int i = 0; i < m; ++i) {
        count_a[a[i]]++;
    }

    vector<int> result;
    if (count_a == count_b) {
        result.push_back(1);
    }

    for (int i = m; i < n; ++i) {
        count_a[a[i]]++;
        count_a[a[i - m]]--;
        if (count_a == count_b) {
            result.push_back(i - m + 2);
        }
    }

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i + 1 == result.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}