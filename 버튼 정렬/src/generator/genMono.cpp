#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>("n");
    vector<int> v(n);
    
    int changes = opt<int>("changes");
    bool reverse = opt<bool>("reverse");
    
    assert(changes <= n-1);
    
    v[0] = rnd.next(1 + 100'000, 1'000'000'000 - 100'000);
    for (int i = 1 ; i < n ; i++) {
        int p = rnd.next(1, n-i);
        if (p <= changes) {
            changes--;
            if (reverse) v[i] = v[i-1]-1;
            else v[i] = v[i-1]+1;
        }
        else v[i] = v[i-1];
    }
    
    long long q = rnd.next(1LL, 1'000'000'000'000'000'000);
    
    cout << n << '\n';
    cout << v[0];
    for (int i = 1 ; i < n ; i++) cout << ' ' << v[i];
    cout << '\n';
    cout << q << '\n';
}