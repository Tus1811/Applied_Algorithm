#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e9 + 7;

long long changeStringtoInt(string str) {
    string str1 = str.substr(0,10);
    string str2 = str.substr(10, str.length() - 10);
    int num1 = stoi(str1);
}

long long expMod(long long a, long long b) {
    int y = (int) b % MAXN;
    int x = (int) a % MAXN;
    long long z = 1;
    for (int i = 0; i < y; i++) {
        z = z * x % MAXN;
    }
    return z;
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << expMod() << endl;
    return 0;
}