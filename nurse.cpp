#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int a_nghi[1001];
int a_lam_viec[1001];

int solve(int n, int k1, int k2) {
    a_nghi[0] = 1;
    a_nghi[1] = 1;
    a_lam_viec[k1] = 1;
    a_lam_viec[k1 + 1] = 2;
    a_nghi[k1 + 1] = 1;
    for (int i = k1 + 2; i <= n; i++) { 
        a_nghi[i] = a_lam_viec[i-1];
        for (int j = k1; j <= min(i,k2); j++) {
            a_lam_viec[i] = (a_lam_viec[i] + a_nghi[i-j]) % MOD;
        }
    } 
    return (a_lam_viec[n] + a_nghi[n]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    cout << solve(n, k1, k2) << endl;
    return 0;
}