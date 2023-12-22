#include<bits/stdc++.h>
using namespace std;

vector<pair<long long int, long long int>> a_pos;
vector<pair<long long int, long long int>> a_neg;
long long n, k, cap, res = 0;

void Init() {
    cin >> n >> k;
    long long xi, mi;
    for (int i = 0; i < n; i++) {
        cin >> xi >> mi;
        if (xi > 0) a_pos.push_back({xi,mi});
        else a_neg.push_back({-xi,mi});
    }
    sort(a_pos.begin(), a_pos.end());
    sort(a_neg.begin(), a_neg.end());
}

void Solve() {
    while (a_pos.size()){
        cap = k;
        if (a_pos.back().second % k == 0) {
            res += 2 * a_pos.back().first * (a_pos.back().second / k);
            a_pos.pop_back();
            continue;
        }
        res += 2 * a_pos.back().first;
        while (cap && a_pos.size()) {
            long long x = min(cap, a_pos.back().second);
            cap -= x;
            a_pos.back().second -= x;
            if (!a_pos.back().second) a_pos.pop_back();
        }
    }

    while (a_neg.size()){
        cap = k;
        if (a_neg.back().second % k == 0) {
            res += 2 * a_neg.back().first * (a_neg.back().second / k);
            a_neg.pop_back();
            continue;
        }
        res += 2 * a_neg.back().first;
        while (cap && a_neg.size()) {
            long long x = min(cap, a_neg.back().second);
            cap -= x;
            a_neg.back().second -= x;
            if (!a_neg.back().second) a_neg.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Init();
    Solve();
    cout << res << endl;
    return 0;
}