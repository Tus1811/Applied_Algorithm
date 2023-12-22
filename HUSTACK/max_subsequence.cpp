#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 7;
int n;
int a[MAXN];

int maxSubsequence() {
    int e[n], s_max;
    e[0] = a[0];
    s_max = a[0];
    for (int i = 0; i < n; i++) {
        e[i] = max(a[i], e[i-1] + a[i]);
        if (e[i] > s_max) s_max = e[i];
    }
    return s_max;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << maxSubsequence();
    return 0;
}