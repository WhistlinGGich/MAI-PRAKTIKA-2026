#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, f;
    if (!(cin >> n >> m >> s >> f)) return 0;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }

    vector<int> dist(n + 1, INF);
    deque<int> dq;

    dist[s] = 0;
    dq.push_back(s);

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        if (u == f) {
            break;
        }

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 0) {
                    dq.push_front(v);
                } else {
                    dq.push_back(v);
                }
            }
        }
    }

    cout << dist[f] << "\n";

    return 0;
}