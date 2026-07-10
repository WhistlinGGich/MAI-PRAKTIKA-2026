#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long min_padding(long long c0, long long c1, long long c2) {
    long long pad = 0;
    
    long long m = min(c1, c2);
    c1 -= m;
    c2 -= m;
    
    c0 %= 2; 
    
    if (c0 == 1) {
        if (c1 > 0) {
            pad += 2;
            c1--;
        } else if (c2 > 0) {
            pad += 1;
            c2--;
        }
    }
    
    pad += (c1 / 2) * 1;
    pad += (c2 / 2) * 2;
    
    return pad;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long s;
    if (!(cin >> n >> s)) return 0;

    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    sort(w.begin(), w.end());

    vector<long long> pref_sum(n + 1, 0);
    vector<long long> pref_c0(n + 1, 0);
    vector<long long> pref_c1(n + 1, 0);
    vector<long long> pref_c2(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        pref_sum[i + 1] = pref_sum[i] + w[i];
        pref_c0[i + 1] = pref_c0[i] + (w[i] % 3 == 0 ? 1 : 0);
        pref_c1[i + 1] = pref_c1[i] + (w[i] % 3 == 1 ? 1 : 0);
        pref_c2[i + 1] = pref_c2[i] + (w[i] % 3 == 2 ? 1 : 0);
    }

    auto check = [&](int k) {
        if (k == 0) return true;
        if (k == 1) return s >= 1;
        if (k == 2) return s >= 2;

        long long mid_elements = k - 2;
        long long sum_W = pref_sum[mid_elements];
        long long c0 = pref_c0[mid_elements];
        long long c1 = pref_c1[mid_elements];
        long long c2 = pref_c2[mid_elements];

        if (mid_elements % 2 != 0) {
            c0++;
        }

        long long pad = min_padding(c0, c1, c2);
        long long mid_cost = (sum_W + pad) / 3;
        long long total_cost = 2 + mid_cost;

        return total_cost <= s;
    };

    long long low = 1, high = min((long long)n, s), ans = 1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}