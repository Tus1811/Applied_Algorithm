#include <bits/stdc++.h>
using namespace std;

int n;
int v[21];
int x[21][21];
bool visited[21];
int res = 10000, tmp = 0, x_min = 10000;

void TSPSolve(int k) {
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            v[k] = i;
            visited[i] = true;
            tmp += x[v[k-1]][v[k]];
            if (k == n) {
                res = min (res, tmp + x[v[k]][1]);
            }
            else {
                if (tmp + (n + 1 - k) * x_min < res) TSPSolve(k + 1);
            }
            visited[i] = false;
            tmp -= x[v[k-1]][v[k]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("test.inp" , "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x[i][j];
            if (x[i][j] < x_min) x_min = x[i][j];
        }
    }
    v[1] = 1;
    TSPSolve(2);
    cout << res;
    return 0;
}