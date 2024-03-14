#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    int h = min(40LL, n);

    int k = 0;
    for (int i = h-1 ; i >= 0 ; i--) {
        k *= 2;
        k += s[i] - '1';
    }

    int ans = 0;
    for (int i = 0 ; i < h ; i++) {
        int bef_p = k/(1LL<<(i+1)), bef_i = k%(1LL<<(i+1));
        int aft_p = (k+t-1)/(1LL<<(i+1)), aft_i = (k+t-1)%(1LL<<(i+1));

        if (bef_p == aft_p) { // bef_i <= aft_i
            if ((bef_i < (1LL<<i)) != (aft_i < (1LL<<i))) {
                ans += min((1LL<<i) - bef_i, aft_i - (1LL<<i) + 1);
            } 
        }
        else {
            if (bef_i < (1LL<<i)) ans += (1LL<<i) - bef_i;
            if (aft_i >= (1LL<<i)) ans += aft_i - (1LL<<i) + 1;
            ans += (aft_p - bef_p - 1)*(1LL<<i);
        }
    }

    if (k+t-1 >= (1LL<<h)) {
        for (int i = h ; i < n ; i++) {
            if (s[i] == '1') {
                ans += min((1LL<<h) - k, k+t-(1LL<<h));
                break;
            }
        }
    }

    cout << ans << endl;
}