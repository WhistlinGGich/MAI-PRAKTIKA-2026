#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rect {
    int x1, y1, x2, y2;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Rect> clouds(n);
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        clouds[i].x1 = min(x1, x2);
        clouds[i].x2 = max(x1, x2);
        clouds[i].y1 = min(y1, y2);
        clouds[i].y2 = max(y1, y2);
    }

    int m;
    cin >> m;
    vector<int> sx(m + 1, 0);
    vector<int> sy(m + 1, 0);
    for (int i = 1; i <= m; ++i) {
        int dx, dy;
        cin >> dx >> dy;
        sx[i] = sx[i - 1] + dx;
        sy[i] = sy[i - 1] + dy;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        
        int qx = x - sx[t];
        int qy = y - sy[t];

        bool rain = false;
        for (int j = 0; j < n; ++j) {
            if (qx >= clouds[j].x1 && qx <= clouds[j].x2 &&
                qy >= clouds[j].y1 && qy <= clouds[j].y2) {
                rain = true;
                break;
            }
        }
        
        if (rain) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}