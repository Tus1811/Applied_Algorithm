#include <bits/stdc++.h>
using namespace std;

int n;
int x[25];
int c[25][25];
bool visited[13];
int res = 10000, tmp = 0, cMin = 10000;

void routing(int k) {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            x[k] = i;
            x[k + 1] = i + n;
            visited[i] = true;
            tmp += c[x[k-1]][x[k]] + c[x[k]][x[k+1]];
            if (k == 2*n - 1) {
                res = min(tmp + c[x[k + 1]][x[0]], res);
            }
            else {
                if (tmp + (2*n - k)*cMin < res) routing(k + 2); 
            }
            visited[i] = false;
            tmp -= c[x[k-1]][x[k]] + c[x[k]][x[k+1]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("test.inp" , "r", stdin);

    cin >> n;
    for (int i = 0; i <= 2*n; i++)
        for (int j = 0; j <= 2*n; j++) {
            cin >> c[i][j];
            if (c[i][j] < cMin) cMin = c[i][j];
        }
    routing(1);
    cout << res;
    return 0;
}