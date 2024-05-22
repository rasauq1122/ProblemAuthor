#define _USE_MATH_DEFINES

#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int r = opt<int>("r");
    int ty = opt<int>("type");
    int shfl = opt<bool>("shuffle");
    
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        v[i] = rnd.next(1, r);
    }
    
    if (ty == 1) {
        sort(v.begin(), v.end());
    }
    else if (ty == 2) {
        sort(v.begin(), v.end());
        for (int i = 0 ; i < n/2 ; i += 2) swap(v[i], v[n-1-i]); 
    }
    
    vector<tuple<int,int,int>> w;
    
    cout << n << '\n';
    for (int i = 1 ; i <= n ; i++) {
        double theta = 2*M_PI/n*i;
        int x = r * cos(theta);
        int y = r * sin(theta);
        w.push_back(make_tuple(x, y, v[i-1]));
    }
    
    if (shfl) shuffle(w.begin(), w.end());
    
    for (auto [x, y, v_] : w) {
        cout << x << ' ' << y << ' ' << v_ << '\n';
    }
}