#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    for (int i = 1 ; i <= 2 ; i++) {
        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<int> uid(1,INT32_MAX);

        freopen(("max"+to_string(i)+".in").c_str(), "w", stdout);

        int n = INT32_MAX;
        int k = ( i == 1 ? INT64_MAX : (1LL*(INT32_MAX-1)/2+1)*(1LL*(INT32_MAX+1LL)/2+1) );

        cout << n << ' ' << k << '\n';
        
    }

    for (int i = 1 ; i <= 2 ; i++) {

        freopen(("max"+to_string(i)+".out").c_str(), "w", stdout);
        freopen(("max"+to_string(i)+".in").c_str(), "r", stdin);
        
        int n, k;
        cin >> n >> k;

        int lo = 0, hi = n/2+1;
        while (hi - lo > 0) {
            int mid = (hi + lo)/2;
            if ((mid+1)*(n-mid+1) < k) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }

        cout << (((hi+1)*(n-hi+1) == k) ? "YES" : "NO");
    }
}