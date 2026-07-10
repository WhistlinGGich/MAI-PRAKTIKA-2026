#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        pq.push(a);
    }
    
    for (int i = 0; i < n - 1; ++i) {
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();
        
        cout << x << " " << y << "\n";
        
        pq.push(x + y);
    }
    
    return 0;
}