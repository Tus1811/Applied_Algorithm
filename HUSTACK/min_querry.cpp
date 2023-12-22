#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 7;
int n, m, Q;
int a[107]; 
int Min[30][MAXN];
int i[MAXN], j[MAXN];

int rmd(int begin, int end) {
    for (int i = 0; i < n; i++) {
        Min[0][i] = a[i];
    }
    for (int i = 0; i < n; i++) {    
        for (int j = 0; j < log2(n); j++) {
            Min[j + 1][i] = min( Min[j][i], Min[j][i + 1<<i] ); 
        }
    }
    int k = begin - end + 1;
    int l = log2(k);
    return min( Min[l][begin], Min[l][end - 1<<l + 1] );
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);   
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int k = 0; k < m; k++) {
        cin >> i[k] >> j[k];

    }
    for (int k = 0; k < m; k++) {
        Q += rmd(i[k], j[k]);
    }
    cout << Q << "\n";
    return 0;
}