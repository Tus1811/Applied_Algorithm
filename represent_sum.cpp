#include <bits/stdc++.h>
using namespace std;

int k, n;
int x[41];
int sumK = 0;

void printX() {
    for (int i = 1; i <= k; i++) {
        cout << x[i] << " ";
    }
    cout << "\n";
}

void solve(int t) {
    for (int i = x[t-1]; i <= (n - sumK)/(k - t + 1); i++) {
        x[t] = i;
        sumK += i;
        if (t == k - 1) {
            x[k] = n - sumK;
            printX();
        }
        else solve(t+1);
        sumK -= i;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    x[0] = 1;
    cin >> k >> n;
    solve(1);
    return 0;
}