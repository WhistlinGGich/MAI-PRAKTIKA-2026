#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct BlackHole {
    long long mass;
    int id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long omega;
    if (!(cin >> n >> omega)) return 0;
    
    vector<BlackHole> holes(n);
    for (int i = 0; i < n; ++i) {
        cin >> holes[i].mass;
        holes[i].id = i + 1;
    }
    
    sort(holes.begin(), holes.end(), [](const BlackHole& a, const BlackHole& b) {
        return a.mass < b.mass;
    });
    
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (omega <= holes[i].mass) {
            possible = false;
            break;
        }
        omega += holes[i].mass;
    }
    
    if (possible) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << holes[i].id << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}