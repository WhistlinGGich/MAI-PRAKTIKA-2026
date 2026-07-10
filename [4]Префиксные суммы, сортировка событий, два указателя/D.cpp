#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> vals(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        vals[i] = a[i];
    }
    
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    
    int unique_cnt = vals.size();
    vector<int> last_pos(unique_cnt, -1);
    
    int max_len = 0;
    int l = 0;
    for (int r = 0; r < n; ++r) {
        int id = lower_bound(vals.begin(), vals.end(), a[r]) - vals.begin();
        if (last_pos[id] >= l) {
            l = last_pos[id] + 1;
        }
        last_pos[id] = r;
        if (r - l + 1 > max_len) {
            max_len = r - l + 1;
        }
    }
    cout << max_len << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}