#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3001, MAXK = 101;
int N, K;
int c[MAXN], a[MAXN];
int dp[MAXN][MAXK];
int res = 0;

void input() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
}

void setup() {
    dp[1][1] = c[1];
    int tmp = 0;
    for (int i = 2; i <= 1 + a[1]; i++) {
        dp[i][2] = c[1] + c[i];
    }
}

void solve() {
    for (int i = 3; i <= N; i++) {
        for (int t = 3; t <= K + 1; t++) {
            int max_good = 0;
            for (int j = t - 1; j < i; j++) {
                if (i >= t && i - j <= a[j])
                    max_good = max(max_good, dp[j][t-1] + c[i]);
            }
            if (max_good == c[i]) dp[N][K + 1] = -1;
            else dp[i][t] = max_good;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    setup();
    solve();
    cout << dp[N][K + 1];
    return 0;
}
