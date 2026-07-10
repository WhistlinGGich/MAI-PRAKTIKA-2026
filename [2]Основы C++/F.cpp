#pragma GCC optimize("O3,unroll-loops")
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long a0;
    if (!(cin >> n >> a0)) return 0;
    
    long long max1 = -1;
    long long max2 = -1;
    long long current = a0;
    const long long mod = 1000000007;
    
    for (int i = 0; i < n; ++i) {
        current = (current * 5) % mod;
        if (current > max1) {
            max2 = max1;
            max1 = current;
        } else if (current > max2) {
            max2 = current;
        }
    }
    
    cout << max2 << " " << max1 << "\n";
    
    return 0;
}