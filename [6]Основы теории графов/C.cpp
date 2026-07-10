#include <iostream>
#include <vector>

using namespace std;

bool dfs(int curr, int target, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& path) {
    visited[curr] = true;
    path.push_back(curr);
    
    if (curr == target) {
        return true;
    }
    
    for (int next_node : adj[curr]) {
        if (!visited[next_node]) {
            if (dfs(next_node, target, adj, visited, path)) {
                return true;
            }
        }
    }
    
    path.pop_back();
    return false;
}

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

    vector<bool> visited(n + 1, false);
    vector<int> path;

    if (dfs(u, v, adj, visited, path)) {
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << (i + 1 == path.size() ? "" : " ");
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}