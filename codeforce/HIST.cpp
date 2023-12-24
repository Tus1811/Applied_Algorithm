#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e7 + 1;
int n; 
ll l[MAXN];

ll solve(){
    int R[n+2];
    int L[n+2];
    l[0] = -1;
    l[n+1] = -1;
    stack<int> s, t; 
    for(int i=1; i<=n+1; i++){
        while(!s.empty() && l[i] < l[s.top()]){
            R[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    for(int i=n; i>=0; i--){
        while(!t.empty() && l[i] < l[t.top()]){
            L[t.top()] = i;
            t.pop();
        }
        t.push(i);
    }

    ll res = 0;
    for(int i=1; i<=n; i++){
        res = max (res, l[i]*(R[i]-L[i]-1));
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    do {
        cin >> n; 
        if (n == 0) break;
        for(int i = 1; i <= n; i++){
            cin >> l[i];
        }
        l[0] = 0;

        cout << solve() << endl;
    } while (n != 0);

    return 0;
}