#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int val = opt<int>("v");
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        v[i] = rnd.next(1, val);
    }
    
    cout << n << '\n';
    for (int i = 0 ; i < n ; i++) {
        int ty = rnd.next(4);
        int k = (ty % 2 ? 1'000'000'000 : -1'000'000'000);
        int x = rnd.next(-1'000'000'000, 1'000'000'000);
        int y = rnd.next(-1'000'000'000, 1'000'000'000);
        if (ty < 2) y = k;
        else x = k;
        cout << x << ' ' << y << ' ' << v[i] << endl;
    }
}