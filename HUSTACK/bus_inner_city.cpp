#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+7;
const int INF = 1e9;
int n, m;

int C[N], D[N];
int W[N][N];
vector<int> dist(N, INF), edge_dist(N, 0);
bool visited[N];
vector<int> adj[N];

void BFS(int s) {
    memset(visited, 0, sizeof(visited));
    queue<int> Q;
    edge_dist[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        visited[u] = true;
        W[s][u] = C[s];
        for (int v: adj[u]) {
            if (!visited[v]) {
                edge_dist[v] = edge_dist[u] + 1;
                if (edge_dist[v] <= D[s]) {
                    Q.push(v);
                }
            }
        }
    }
}

void buildGraph() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            W[i][j] = i == j ? 0 : INF;
        }
    }

    for (int i = 0; i < n; i++) {
        BFS(i);
    }
}

void Dijkstra(int s, int t) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;
    dist[s] = 0;
    PQ.push(make_pair(0, s));
    while (!PQ.empty()) { 
        int u = PQ.top().second;
        PQ.pop();
        for (int v = 1; v <= n; v++) {
            if (W[u][v] < INF) {
                if (dist[v] > dist[u] + W[u][v]) {
                    dist[v] = dist[u] + W[u][v];
                    PQ.push(make_pair(dist[v], v));
                }
            }
        }
    }
}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> C[i] >> D[i];
    }
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    buildGraph();
    Dijkstra(1, n);
    cout << dist[n] << endl;
    return 0;
}