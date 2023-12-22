#include<bits/stdc++.h>

using namespace std;

const int MAXN = 999 + 9;
int a[MAXN][MAXN];
int d[MAXN][MAXN];
int m,n,r,c;
queue<pair<int,int> > q;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int solve() {
    q.push(make_pair(r,c));
    bool visited[n+1][m+1];
    visited[r][c] = true;
    while(!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        int x = u.first;
        int y = u.second;
        for (int i = 0; i < 4; i++) {
            int x = u.first + dx[i];
            int y = u.second + dy[i];
            if (x < 1 || y < 1 || x > n || y > m) {
                return d[u.first][u.second] + 1;
            }
            if (!a[x][y] && !visited[x][y]){
                q.push(make_pair(x,y));
                visited[x][y] = true;
                d[x][y] = d[u.first][u.second] + 1;
            }
        }
    }
    return -1;
}

void input() {
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

int main() {
    ios_base :: sync_with_stdio (0);
    cin . tie (0); 
    cout . tie (0);
    input();
    int result = solve();
    cout << result << endl;
    return 0;
}