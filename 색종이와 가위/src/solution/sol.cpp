#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
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