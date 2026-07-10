#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long total_triplets = 0;
    int l = 0;

    for (int r = 0; r < n; ++r) {
        while (a[r] - a[l] > k) {
            l++;
        }
        
        long long count = r - l;
        
        if (count >= 2) {
            total_triplets += (count * (count - 1)) / 2;
        }
    }

    cout << total_triplets << "\n";

    return 0;
}