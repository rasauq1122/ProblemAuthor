#include <bits/stdc++.h>
using namespace std;

int main() {
    string ss;
    cin >> ss;

    freopen((ss+".out").c_str(), "w", stdout);
    freopen((ss+".in").c_str(), "r", stdin);

    string s;
    cin >> s;

    int r = 0, len = s.size();
    for (int i = 0 ; i < len ; i++) {
        r += s[i] == 'R';
    }

    int k1 = 0, k2 = 0, i = 0, j = len-1, da = r;
    
    while (da) {
        bool chk1 = k1 <= k2, chk2 = k1 >= k2; 
        
        if (chk1) {
            while (s[i] == 'K') {
                k1++;
                i++;
            }
        }
        
        if (chk2) {
            while (s[j] == 'K') {
                k2++;
                j--;
            }
        }

        da = max(da, r + 2*min(k1, k2));
        
        if (k1 <= k2) {
            r--;
            i++;
        }

        if (k2 <= k1) {
            r--;
            j--;
        }

        if (i > j) {
            break;
        }
    }

    cout << da;
}