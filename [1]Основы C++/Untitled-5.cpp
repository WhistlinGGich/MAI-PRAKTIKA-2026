#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<int> a(n + 1);
    int global_min_idx = 1;
    int global_max_idx = 1;

    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        if (i == 1) continue;
        if (a[i] < a[global_min_idx]) global_min_idx = i;
        if (a[i] > a[global_max_idx]) global_max_idx = i;
    }

    std::vector<int> local_mins;
    std::vector<int> local_maxs;

    if (n == 1) {
        local_mins.push_back(1);
        local_maxs.push_back(1);
    } else {
        if (a[1] < a[2]) local_mins.push_back(1);
        if (a[1] > a[2]) local_maxs.push_back(1);

        for (int i = 2; i < n; ++i) {
            if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
                local_mins.push_back(i);
            }
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                local_maxs.push_back(i);
            }
        }

        if (a[n] < a[n - 1]) local_mins.push_back(n);
        if (a[n] > a[n - 1]) local_maxs.push_back(n);
    }

    std::cout << local_mins.size();
    for (int idx : local_mins) {
        std::cout << " " << idx;
    }
    std::cout << "\n";

    std::cout << local_maxs.size();
    for (int idx : local_maxs) {
        std::cout << " " << idx;
    }
    std::cout << "\n";

    std::cout << global_min_idx << " " << global_max_idx << "\n";

    return 0;
}