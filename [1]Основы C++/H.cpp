#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    unsigned long long n;
    int k;
    if (!(std::cin >> n >> k)) return 0;

    if (k >= 60) {
        std::cout << -1 << "\n";
        return 0;
    }

    unsigned long long p = 1ULL << k;
    if (p > n) {
        std::cout << -1 << "\n";
        return 0;
    }

    unsigned long long limit = n / p;
    if (limit % 2 == 0) {
        std::cout << (limit - 1) * p << "\n";
    } else {
        std::cout << limit * p << "\n";
    }

    return 0;
}