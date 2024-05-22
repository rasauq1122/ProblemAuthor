#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int r = opt<int>("r");
    bool o = opt<bool>("O");
 
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        v[i] = rnd.next(1, r);
    }
    
    vector<tuple<int,int,int>> w;
    
    cout << n << '\n';
    int x = o ? 0 : rnd.next(-r, r);
    int y = o ? 0 : rnd.next(-r, r);  
    for (int i = 0 ; i < n ; i++) {     
        w.push_back(make_tuple(x, y, v[i]));
    }
    
    for (auto [x, y, v_] : w) {
        cout << x << ' ' << y << ' ' << v_ << '\n';
    }
}