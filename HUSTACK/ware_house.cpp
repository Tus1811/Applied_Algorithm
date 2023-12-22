#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001, MAXT = 101;
int n, time_limit, d;
int a[MAXN], times[MAXN];
int dp[MAXN][MAXT];
int temp = 0;

void input() {
    cin >> n >> time_limit >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> times[i];
    }
}

void solve() {
    for (int t = 1; t <= time_limit; t++) {
        if (t >= times[1]) dp[1][t] = a[1];
    }

    for (int i = 2; i <= n; i++) {
        for (int t = 1; t <= time_limit; t++) {
            int max_weight = 0;
            for (int j = max (i - d, 1); j < i; j++) {
                if (t - times[i] >= 0) {
                    max_weight = max(dp[j][t - times[i]] + a[i], max_weight);
                }
            }
            dp[i][t] = max_weight;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= time_limit; j++)
            dp[i][j] = 0;
    input();
    solve();
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[i][time_limit]);
    }
    cout << res << endl;
    return 0;
}

