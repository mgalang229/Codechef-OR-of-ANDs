#include <bits/stdc++.h>

using namespace std;

void BitFrequency(int x, int* frequency, int add_sub) {
    for (int i = 0; i < 32; i++) {
        if (x & (1 << i)) {
            frequency[i] += add_sub;
        }
    }
}

int Calculate(int frequency[]) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        if (frequency[i] >= 1) {
            ans += (1 << i);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        // input
        int n, q;
        cin >> n >> q;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        pair<int, int> p[q];
        for (int i = 0; i < q; i++) {
            cin >> p[i].first >> p[i].second;
        }
        // add frequency for every set bit
        int frequency[32] = {0};
        for (int i = 0; i < n; i++) {
            BitFrequency(a[i], frequency, 1);
        }
        // calculate the number (based on the set bits)
        int ans = Calculate(frequency);
        cout << ans << '\n';
        for (int i = 0; i < q; i++) {
            // add the set bits of the new value
            BitFrequency(p[i].second, frequency, 1);
            // remove the set bits of the former value
            BitFrequency(a[p[i].first - 1], frequency, -1);
            // change the value
            a[p[i].first - 1] = p[i].second;
            // calculate the new result
            cout << Calculate(frequency) << '\n';
        }
        cout << '\n';
    }
    return 0;
}
