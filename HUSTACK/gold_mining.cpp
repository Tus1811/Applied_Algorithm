#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, L1, L2;
    cin >> n >> L1 >> L2;

    vector<long long> a(n+1), dp(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Kh?i t?o giá tr? ban d?u cho dp
    for (int i = 1; i <= L1 && i <= n; ++i) {
        dp[i] = a[i];
    }

    // C?p nh?t dp v?i m?i kho
    for (int i = 1; i <= n; ++i) {
        if (i > L1) {
            dp[i] = max(dp[i], dp[i - L1] + a[i]);
        }
        if (i > L2) {
            dp[i] = max(dp[i], dp[i - L2] + a[i]);
        }
        // C?p nh?t dp[i] v?i giá tr? t?i uu tru?c dó
        if (i > 1) {
            dp[i] = max(dp[i], dp[i - 1]);
        }
    }

    cout << dp[n] << endl;
    return 0;
}