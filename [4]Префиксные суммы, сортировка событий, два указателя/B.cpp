#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> L(n), R(n);
    vector<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.back()] < a[i]) {
            st.pop_back();
        }
        L[i] = st.empty() ? -1 : st.back();
        st.push_back(i);
    }

    st.clear();

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.back()] <= a[i]) {
            st.pop_back();
        }
        R[i] = st.empty() ? n : st.back();
        st.push_back(i);
    }

    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        total_sum += a[i] * (i - L[i]) * (R[i] - i);
    }

    cout << total_sum << "\n";

    return 0;
}