#include "testlib.h"
#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}

int lcd(int x, int y) {
    return x/gcd(x, y)*y;
}

signed main(signed argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    signed n = opt<signed>("n");
    signed r = opt<signed>("r");
    signed val = opt<signed>("v");
    bool minus = opt<bool>("minus");
    
    vector<int> v(n);
    int a = rnd.next(r), b = rnd.next(r);
    int l = lcd(a, b);
    while (l/1'000'000'000) {
         a = rnd.next(r), b = rnd.next(r), l = lcd(a, b);
    }
    
    for (int i = 0 ; i < n ; i++) {
        v[i] = rnd.next(1, val);
    }
    
    cout << n << '\n';
    for (int i = 0 ; i < n ; i++) {
        int x = l/a * rnd.next(-1'000'000'000/l, 1'000'000'000/l);
        int y = a*x/b;
        if (minus) y *= -1;
        cout << x << ' ' << y << ' ' << v[i] << endl;
    }
}