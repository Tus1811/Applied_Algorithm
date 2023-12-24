#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int f[] = {0, 1, 1, 1, 2, 1, 2, 2, 2, 3};
int g[] = {1, 1, 1, 1, 2, 1, 2, 1, 1, 3};
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    ll n;
    cin >> n;
    while (n--) {
        ll W, c;
        cin >> W >> c;
        ll N = 0, S = 1;
        if (W % 1000 != 0) {
            cout << "0" << endl;
            continue;
        }
        W = W/1000;
        ll a = W, b;
        for (ll i = 0; i < c; i++) {
            b = a % 10;
            a = a / 10;
            S *= g[b];
            N += f[b];
        }
        ll quo = a / 5;
        ll rem = a % 5;
        if (quo >= 1) {
            quo --;
            rem += 5;
        }
        N += quo + f[rem];
        S *= g[rem];
        cout << N << " " << S << endl;
    }
 
    return 0;
}