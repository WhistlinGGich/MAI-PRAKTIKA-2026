#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    long long count = 0;
    for (int i = 0; i < n; ++i) {
        int k = i + 2;
        for (int j = i + 1; j < n; ++j) {
            if (k <= j) {
                k = j + 1;
            }
            while (k < n && a[i] + a[j] > a[k]) {
                k++;
            }
            count += (k - 1) - j;
        }
    }
    
    cout << count << "\n";
    
    return 0;
}