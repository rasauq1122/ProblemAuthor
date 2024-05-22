#define _USE_MATH_DEFINES

#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    int l = opt<int>("l");
    int r = opt<int>("r");
    int val = opt<int>("v");
    assert(l*l <= 111'222);
    vector<int> v(l*l);
    int n = l*l;
    for (int i = 0 ; i < n ; i++) {
        v[i] = rnd.next(1, val);
    }
    
    vector<tuple<int,int,int>> w;
    
    cout << n << '\n';
    int x = rnd.next(-min(r-1, 1'000'000'000 -(l+1)/2), min(r-1, 1'000'000'000 -(l+1)/2));
    int y = rnd.next(-min(r-1, 1'000'000'000 -(l+1)/2), min(r-1, 1'000'000'000 -(l+1)/2));
    for (int i = 0 ; i < l ; i++) {
        for (int j = 0 ; j < l ; j++) {
            w.push_back(make_tuple(x+i-(l+1)/2, y+j-(l+1)/2, v[i*l + j]));
        }
    }
    
    for (auto [x, y, v_] : w) {
        cout << x << ' ' << y << ' ' << v_ << '\n';
    }
}