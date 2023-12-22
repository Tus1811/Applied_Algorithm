#include <bits/stdc++.h>
using namespace std;

int k, n;
int a[100001];

void printList() {
    for (int i = 1; i <= k ; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void solve(int m) {
    for (int i = a[m-1] + 1; i <= n - k + m; i++) {
        a[m] = i;
        if  (m == k) printList();
        else solve(m + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> k >> n;
    solve(1);
    return 0;
}