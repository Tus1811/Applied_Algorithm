#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;
int n, m;
int d[MAX];
vector<int> constraint[MAX];
int inDegree[MAX];
int earliestTime[MAX];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        earliestTime[i] = d[i];
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        constraint[a].push_back(b);
        inDegree[b] ++;
    }
}

void solve() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int x : constraint[node]) {
            inDegree[x] --;
            earliestTime[x] = max (earliestTime[x], earliestTime[node] + d[x]);
            if (inDegree[x] == 0) q.push(x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    solve();
    cout << *max_element(earliestTime + 1, earliestTime + n + 1) << endl;
    return 0;
}