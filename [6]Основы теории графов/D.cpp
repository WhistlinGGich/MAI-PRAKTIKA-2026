#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v;
    if (!(cin >> n >> m >> u >> v)) return 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;
    
    dist[v] = 0;
    q.push(v);
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int nxt : adj[curr]) {
            if (dist[nxt] == -1) {
                dist[nxt] = dist[curr] + 1;
                q.push(nxt);
            }
        }
    }

    if (dist[u] == -1) {
        cout << -1 << "\n";
        return 0;
    }

    int curr = u;
    vector<int> path;
    path.push_back(curr);

    while (curr != v) {
        int best_nxt = -1;
        for (int nxt : adj[curr]) {
            if (dist[nxt] == dist[curr] - 1) {
                if (best_nxt == -1 || nxt < best_nxt) {
                    best_nxt = nxt;
                }
            }
        }
        curr = best_nxt;
        path.push_back(curr);
    }

    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << (i + 1 == path.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}