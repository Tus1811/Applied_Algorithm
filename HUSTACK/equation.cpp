#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001;
int a[MAXN], x[MAXN];
int n, M;
int SumK = 0, result = 0;

void solve(int k) {
    for (int i = 1; i <= (M - SumK)/a[k]; i++) {
        x[k] = i;
        SumK += x[k]*a[k];
        if (k == n-1) {
            if ((M - SumK) % a[n] == 0 && M > SumK) {
                result ++;
            }
        }
        else solve(k+1);
        SumK -= x[k]*a[k];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> M;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    solve(1);
    cout << result << endl;
    return 0;
}
