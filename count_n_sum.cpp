#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int n;
long a[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    long result = 0;

    for (int i = 1; i <= n; i++) {
        a[i][1] = 1;
        a[i][i] = 1;
    }

    for (int i = 3; i <= n; i++) {
        for (int j = 2; j < i; j++) {
            a[i][j] = (a[i-1][j-1] + a[i-j][j])%(long)(1e9+7);
        }
    }

    for (int i = 1; i <= n; i++) {
        result = (result + a[n][i])%(long)(1e9+7);
    }
    cout << result << "\n";
    return 0;
}