#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

pair<int,int> nextP(pair<int,int> p, int k) {
    auto [x, y] = p;
    
    if (y == -k && x == k) y++;
    else if (y == -k) x++;
    else if (x == -k) y--;
    else if (y == k) x--;
    else if (x == k) y++;
    
    return make_pair(x, y);
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int r = opt<int>("r");
    int val = opt<int>("v");
    bool corner = opt<bool>("corner");
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        v[i] = rnd.next(1, val);
    }
    
    cout << n << '\n';
    int ty = rnd.next(4);
    int k = (ty % 2 ? r : -r);
    int x, y;
    if (corner) {
        int k = r - rnd.next(1, n-1);
        if (ty == 1 || ty == 2) k *= -1;
        if (ty < 2) x = k;
        else y = k;
    }
    else {
        x = rnd.next(-r, r);
        y = rnd.next(-r, r);
    }
    if (ty < 2) y = k;
    else x = k;
    
    pair<int,int> p = make_pair(x, y);
    for (int i = 0 ; i < n ; i++) {
        cout << p.first << ' ' << p.second << ' ' << v[i] << endl;
        p = nextP(p, r);
    }
}