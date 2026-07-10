#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    if (!(cin >> K)) return 0;

    vector<int> R(K + 1), B(K + 1);
    vector<vector<int>> adj(2005);
    
    for (int i = 1; i <= K; ++i) {
        cin >> R[i] >> B[i];
        adj[R[i]].push_back(i);
    }

    int T, S1, S2;
    cin >> T >> S1 >> S2;

    if (S1 == T || S2 == T) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> dist(K + 1, -1);
    vector<int> parent(K + 1, -1);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int plate_side1, plate_side2;
        if (u == 0) {
            plate_side1 = S1;
            plate_side2 = S2;
        } else {
            plate_side1 = R[u];
            plate_side2 = B[u];
            
            if (plate_side1 == T || plate_side2 == T) {
                vector<int> path;
                int curr = u;
                while (curr != 0) {
                    path.push_back(curr);
                    curr = parent[curr];
                }
                reverse(path.begin(), path.end());
                
                cout << path.size() << "\n";
                for (int i = 0; i < path.size(); ++i) {
                    cout << path[i] << "\n";
                }
                return 0;
            }
        }

        for (int v : adj[plate_side1]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
        
        if (plate_side2 != plate_side1) {
            for (int v : adj[plate_side2]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}