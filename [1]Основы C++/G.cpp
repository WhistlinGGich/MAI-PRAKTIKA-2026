#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, k;
    std::cin >> n >> k;

    long long total_distance = 0;
    long long current_dist = 1;
    long long layer_size = 4 * n;

    while (k > 0) {
        if (k >= layer_size) {
            total_distance += layer_size * current_dist;
            k -= layer_size;
            layer_size += 8;
            current_dist++;
        } else {
            total_distance += k * current_dist;
            k = 0;
        }
    }

    std::cout << total_distance << "\n";

    return 0;
}