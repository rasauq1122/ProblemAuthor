#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    if (k == 1) return cout << "NO\n", 0;
    if (k == n) {
        if (n%2) return cout << "NO\n", 0;
        cout << "YES\n";
        for (int i = 1 ; i <= n ; i++) cout << i << " \n"[i==n]; 
        return 0;
    }
    
    cout << "YES\n";
    if (k % 2) {
        int team = n/k;
    
        for (int i = 1 ; i <= n - (team%2 ? 3*k : 0) ; i++) {
            if (i%k == 2 && (i/k)%2 == 0) cout << i + k - 1 << ' ';
            else if (i%k == 1 && (i/k)%2) cout << i - k + 1 << ' ';
            else cout << i << " \n"[i%k==0];
        }
    
        if (team%2) {
            int tmp = n - k + 1, tg = 3;
            for (int i = n - 3*k + 1 ; i <= n ; i++) {
                if (i != n && i % k == tg % k) {
                    cout << tmp << " \n"[i%k==0];
                    tmp = i;
                    tg--;
                }
                else cout << i << " \n"[i%k==0];
            }
        }
    }
    else {
        for (int i = 1 ; i <= n ; i++) {
            cout << i << " \n"[i%k==0];
        }
    }
}