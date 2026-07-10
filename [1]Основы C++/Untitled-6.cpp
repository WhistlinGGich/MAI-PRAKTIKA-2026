#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    unsigned long long sum_int = 0;
    unsigned long long sum_frac = 0;
    const unsigned long long MOD = 1000000000000000ULL;

    while (std::cin >> s) {
        size_t dot = s.find('.');
        if (dot != std::string::npos) {
            sum_int += std::stoull(s.substr(0, dot));
            sum_frac += std::stoull(s.substr(dot + 1));
        } else {
            sum_int += std::stoull(s);
        }
    }

    sum_int += sum_frac / MOD;
    sum_frac %= MOD;

    std::cout << sum_int << "." << std::setfill('0') << std::setw(15) << sum_frac << "\n";

    return 0;
}