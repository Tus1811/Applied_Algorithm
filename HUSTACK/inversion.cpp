#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 7;
int n;
int a[MAXN];

int mergeAndCount (int start, int mid, int end) {
    int x = mid - start + 1, y = end - mid;
    int left_arr[x];
    int right_arr[y];
    int i = 0, j = 0, k = start;
    int inversions = 0;

    memcpy (left_arr, a + start, sizeof(left_arr));
    memcpy (right_arr, a + mid + 1, sizeof(right_arr));

    while (i < x && j < y) {
        if (left_arr[i] <= right_arr[j]) {
            a[k] = left_arr[i];
            i++;
        }
        else {
            a[k] = right_arr[j];
            j++;
            inversions += (x - i) % MOD;
        }
        k++;
    }

    while (i < x) {
        a[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < y) {
        a[k] = right_arr[j];
        j++;
        k++;
    }

    return inversions % MOD;
}

int countInversions (int start, int end) {
    if (start >= end) return 0;
    int mid = (start + end) / 2;

    int left_inversions = countInversions (start, mid) % MOD;
    int right_inversions = countInversions (mid + 1, end) % MOD;
    int merged_inversions = mergeAndCount (start, mid, end);

    return (left_inversions + right_inversions + merged_inversions) % MOD; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen ("test.inp", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << countInversions(0, n - 1);
    return 0;
}