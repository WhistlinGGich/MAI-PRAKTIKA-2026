#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    priority_queue<int> left_half;
    priority_queue<int, vector<int>, greater<int>> right_half;
    
    for (int k = 1; k <= n; ++k) {
        int x;
        cin >> x;
        
        if (left_half.empty() || x <= left_half.top()) {
            left_half.push(x);
        } else {
            right_half.push(x);
        }
        
        size_t target_left_size = (k + 1) / 2;
        
        if (left_half.size() > target_left_size) {
            right_half.push(left_half.top());
            left_half.pop();
        } else if (left_half.size() < target_left_size) {
            left_half.push(right_half.top());
            right_half.pop();
        }
        
        cout << left_half.top() << "\n";
    }
    
    return 0;
}