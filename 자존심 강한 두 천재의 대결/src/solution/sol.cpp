#include <bits/stdc++.h>
using namespace std;

#define MOD 100'000'000

void bigint(int* x, int v, int m) {
    
    for (int i = 0 ; i < 3; i++) {
        x[i] *= m;
        x[i] += v;
        
        v = x[i]/MOD;
        x[i] %= MOD;
    }
}

int main() {
    int u, v;
    cin >> u >> v;
    
    string s, t;
    cin >> s;
    cin >> t;
    
    int len = s.size();
        
    if (u == v) {
        int winner = 0;
        for (int i = 0 ; i < len ; i++) {
            if (s[i] > t[i]) {
                winner = 1;
                break;
            }
            else if (s[i] < t[i]) {
                winner = -1;
                break;
            }
        }
        
        if (winner) cout << (winner == 1 ? "ras" : "auq") << '\n';
        else cout << "rasauq\n";
    }
    else if (len <= 25) {
        int a[3] = {};
        int b[3] = {};
        
        for (int i = 0 ; i < len ; i++) {
            bigint(a, s[i]-'0', u);
            bigint(b, t[i]-'0', v);
        }
        
        int winner = 0;
        for (int i = 0 ; i < 3 ; i++) {
            if (a[2-i] > b[2-i]) {
                winner = 1;
                break;
            }
            else if (a[2-i] < b[2-i]) {
                winner = -1;
                break;
            }
        }
        
        if (winner) cout << (winner == 1 ? "ras" : "auq") << '\n';
        else cout << "rasauq\n";
    }
    else {
        cout << (u > v ? "ras" : "auq") << '\n';   
    }
}