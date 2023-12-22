#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 7;
//stack<int> Stack;
vector<int> adjList[MAXN];
bool visited[MAXN];
int n,m;

void DFS(int k) {
    visited[k] = true;
    for (int i = 0; i < adjList[k].size(); i++) {
        int x = adjList[k][i];
        if (visited[x] == false) DFS(x);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int a,b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int result = 0;
    for (int i = 1; i <= n; i ++) {
        if (!visited[i]) {
            DFS(i);
            result ++;
        }
    }
    cout << result << endl;
    return 0;
}