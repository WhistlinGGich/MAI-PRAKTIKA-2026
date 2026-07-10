#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    
    sort(d.begin(), d.end());
    
    int q;
    if (!(cin >> q)) return 0;
    
    for (int i = 0; i < q; ++i) {
        int s, f;
        cin >> s >> f;
        
        int l = min(s, f);
        int r = max(s, f);
        
        auto it_start = lower_bound(d.begin(), d.end(), l);
        auto it_end = upper_bound(d.begin(), d.end(), r);
        
        cout << distance(it_start, it_end) << "\n";
    }
    
    return 0;
}