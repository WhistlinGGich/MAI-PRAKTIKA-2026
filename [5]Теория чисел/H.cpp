#include <iostream>

using namespace std;

const int MAXN = 40000000;
int lp[MAXN + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i <= MAXN; i += 2) {
        lp[i] = 2;
    }
    
    for (int i = 3; i * i <= MAXN; i += 2) {
        if (lp[i] == 0) {
            lp[i] = i;
            for (int j = i * i; j <= MAXN; j += i * 2) {
                if (lp[j] == 0) {
                    lp[j] = i;
                }
            }
        }
    }
    
    for (int i = 3; i <= MAXN; i += 2) {
        if (lp[i] == 0) {
            lp[i] = i;
        }
    }

    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            
            if (n == 1) {
                cout << 0 << "\n";
            } else if (lp[n] == n) {
                cout << "Prime\n";
            } else {
                int count = 0;
                int current_p = 0;
                int temp = n;
                
                while (temp > 1) {
                    int p = lp[temp];
                    if (p != current_p) {
                        count++;
                        current_p = p;
                    }
                    temp /= p;
                }
                
                cout << count << "\n";
            }
        }
    }

    return 0;
}