#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100000];
long long q;

pair<int, int> nax;

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> arr[i];
    cin >> q;

    for (int i = 0 ; i < n-1 ; i++) {
        if (arr[i] > arr[i+1]) nax = max(nax, {arr[i], -i});
    }

    long long btn = 0;
    auto [k, idx] = nax;
    for (int i = 0 ; i < n ; i++) {
        btn += max(0, k - arr[i]); 
        if (arr[i] < k) arr[i] = k;
    }

    if (btn > q) return cout << 0 << '\n', 0;
    long long cnt = btn != 0;
    for (int i = 0 ; i < n ; i++) {
        while (i < n && arr[i] == arr[i+1]) i++;
        if (i < n-1) {
            int k = arr[i+1] - arr[i];
            if (k < (q - btn)/(i+1)) {
                cnt += k;
                btn += k*(i+1);
            }
            else {
                cnt += 1LL*(q - btn)/(i+1);
                break;
            }
        }
        else cnt += 1LL*(q - btn)/n;
    }

    cout << cnt << '\n';
}