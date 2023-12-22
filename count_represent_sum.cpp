#include <bits/stdc++.h>
using namespace std;

int n;
int a[50];
int sumK = 0, res = 0;

void solve(int k) {
    if (n - sumK >= a[k-1]) {
        for (int i = a[k-1]; i <= n - sumK ; i++) {
            a[k] = i;
            sumK += i;
            if (n == sumK) res ++;
            else solve(k + 1);
            sumK -= i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    a[0] = 1;
    solve(1);
    cout << res << "\n";
    return 0;
}