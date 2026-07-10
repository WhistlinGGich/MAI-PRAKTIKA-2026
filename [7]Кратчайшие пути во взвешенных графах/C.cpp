#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int weight;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s;
    if (!(cin >> n >> m >> s)) return 0;

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> max_width(n + 1, 0);
    priority_queue<pair<int, int>> pq;

    max_width[s] = 2e9; 
    pq.push({2e9, s});

    while (!pq.empty()) {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (w < max_width[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.to;
            int weight = edge.weight;
            int min_w = min(max_width[u], weight);
            
            if (min_w > max_width[v]) {
                max_width[v] = min_w;
                pq.push({max_width[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i == s) {
            cout << -1;
        } else {
            cout << max_width[i];
        }
        cout << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}