#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e7 + 1;
ll N, M;
int trees[MAXN];

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> trees[i];
    }
    sort(trees + 1, trees + N + 1);
}

ll wood_sum(int m) {
    ll tmp = 0;
    for (ll i = N; i >= 1; i--) {
        int x = trees[i];
        if (x > m) {
            tmp += x - m;
        }
        else break;
    }
    return tmp;
}

int solve(int start, int end) {
    if (start > end) return end;
    else {
        int mid = (start + end) / 2;
        ll a = wood_sum(mid);
        if (a == M) return mid;
        else if (a > M) return solve(mid + 1, end);
        else return solve(start, mid - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    cout << solve(0, trees[N]);
    return 0;
}

