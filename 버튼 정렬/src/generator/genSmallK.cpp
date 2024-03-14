#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(1, 100'000);
    vector<int> v(n);
    
    for (int i = 0 ; i < n ; i++) v[i] = rnd.next(2, 1'000'000'000 - 10);
    
    cout << n << '\n';
    cout << v[0];
    for (int i = 1 ; i < n ; i++) cout << ' ' << v[i];
    cout << '\n';
    
    long long nax  = 0;
    for (int i = 0 ; i < n-1 ; i++) {
        if (v[i] > v[i+1]) nax = max(nax, ++v[i]*1LL);
    }
 
    if (!nax) {
        swap(v[0], v[n-1]);
        nax = (v[0] += 2);
    }
    
    long long btn = 0;
    for (int i = 0 ; i < n ; i++) btn += max(0LL, nax - v[i]);
    
    long long q = rnd.next(1LL, btn-1);
    cout << q;
    cout << '\n';
}
