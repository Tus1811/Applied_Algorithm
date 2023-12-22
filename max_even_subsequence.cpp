#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 7;
int n;
int arr[MAXN];
long long odd_arr[MAXN], even_arr[MAXN]; 

long long maxEvenSubsequence () {
	long long smax = INT_MIN;
	odd_arr[0] = INT_MIN; 
	even_arr[0] = INT_MIN;

	for (int i = 1; i <= n; i++) { 
		if (arr[i] % 2 == 0) {
			even_arr[i] = max((long long)arr[i], even_arr[i-1] + arr[i]);
			odd_arr[i] = odd_arr[i-1] + arr[i];
		}
		else {
			even_arr[i] = odd_arr[i-1] + arr[i];
			odd_arr[i] = max((long long)arr[i], even_arr[i-1] + arr[i]);
		}
		smax = max (smax, even_arr[i]);
	}
	return smax; 
}

main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("test.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
		cin >> arr[i];
    }
	cout << maxEvenSubsequence();
	return 0;
}

