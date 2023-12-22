#include <bits/stdc++.h>
using namespace std;

const int MAXN = 12;
int n,k;
int a[2*MAXN];
int c[2*MAXN][2*MAXN];
bool visited[2*MAXN];
int passengers = 0, temp = 0, result = 1e9, cMin = 1e9;

void input() {
    cin >> n >> k;
    for (int i = 0; i <= 2*n; i++) {
        for (int j = 0; j <= 2*n; j++) {
            cin >> c[i][j];
            if (i != j) cMin = min(cMin, c[i][j]);
        }
    }
}

bool check(int i) {
    if (visited[i] == true) return false;
    if (i > n) return visited[i-n];
    return passengers < k;
}

void solve(int x) {
    for (int i = 1; i <= 2*n; i++) {
        if (check(i)) {
            a[x] = i;
            visited[i] = true;
            if (i <= n) passengers ++;
            else passengers --;
            temp += c[a[x-1]][a[x]];
            if(x == 2*n) result = min(temp + c[a[2*n]][0], result);
            else {
                if (temp + cMin*(2*n - x) < result) solve(x+1);
            }
            visited[i] = false;
            temp -= c[a[x-1]][a[x]];
            if (i <= n) passengers --;
            else passengers ++;
        } 
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    solve(1);
    cout << result;
    return 0;
}




