#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); i++) {
        v[i] = v[i] + i + 1;
    }
    int res = *max_element(v.begin(), v.end());
    cout << res + 1 << endl;
    return 0;
}