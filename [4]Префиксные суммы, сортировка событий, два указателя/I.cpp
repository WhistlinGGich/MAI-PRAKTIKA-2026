#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Block {
    long long req;
    long long gain;
    
    bool operator<(const Block& other) const {
        if (req != other.req) {
            return req < other.req;
        }
        return gain > other.gain;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x;
    int k;
    if (!(cin >> x >> k)) return 0;

    vector<Block> all_blocks;
    all_blocks.reserve(k);
    
    for (int i = 0; i < k; ++i) {
        int l;
        cin >> l;
        vector<Block> st;
        for (int j = 0; j < l; ++j) {
            long long v;
            cin >> v;
            Block B;
            if (v >= 0) {
                B = {0, v};
            } else {
                B = {-v, v};
            }
            
            while (!st.empty()) {
                Block A = st.back();
                if (A.gain <= 0 || (B.gain > 0 && A.req >= B.req)) {
                    st.pop_back();
                    long long new_req = max(A.req, B.req - A.gain);
                    long long new_gain = A.gain + B.gain;
                    B = {new_req, new_gain};
                } else {
                    break;
                }
            }
            st.push_back(B);
        }
        
        for (const auto& b : st) {
            if (b.gain > 0) {
                all_blocks.push_back(b);
            }
        }
    }

    sort(all_blocks.begin(), all_blocks.end());

    for (const auto& b : all_blocks) {
        if (x >= b.req) {
            x += b.gain;
        } else {
            break;
        }
    }

    cout << x << "\n";

    return 0;
}