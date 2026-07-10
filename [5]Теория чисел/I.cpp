#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        long long dx = abs(x1 - x2);
        long long dy = abs(y1 - y2);
        
        cout << gcd(dx, dy) + 1 << "\n";
    }

    return 0;
}