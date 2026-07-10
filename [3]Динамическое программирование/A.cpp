#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (cin >> n) {
        for (int i = n; i >= 1; --i) {
            cout << i << " ";
        }
        cout << "\n";
    }
    
    return 0;
}