#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define MOD 100'000'000

int MAX[9][9] = {{ 0,  2,  1,  1,  1,  1,  1,  1,  1}, 
                 { 0,  0,  4,  3,  2,  2,  2,  1,  1},
                 { 0,  0,  0,  7,  4,  3,  2,  2,  2}, 
                 { 0,  0,  0,  0,  9,  5,  4,  3,  3}, 
                 { 0,  0,  0,  0,  0, 12,  7,  5,  4}, 
                 { 0,  0,  0,  0,  0,  0, 15,  8,  6}, 
                 { 0,  0,  0,  0,  0,  0,  0, 18, 10}, 
                 { 0,  0,  0,  0,  0,  0,  0,  0, 21}, 
                 { 0,  0,  0,  0,  0,  0,  0,  0,  0}};
 
void bigint(int* x, int v, int m) {
    for (int i = 0 ; i < 3; i++) {
        x[i] *= m;
        x[i] += v;
        
        v = x[i]/MOD;
        x[i] %= MOD;
    }
}

void bigadd(int* x, int v) {
    for (int i = 0 ; i < 3 ; i++) {
        x[i] += v;
        
        v = x[i]/MOD;
        x[i] %= MOD;
    }
}

void bigsub(int* x, int v) {
    for (int i = 0 ; i < 3 ; i++) {
        x[i] -= v;
        v = 0;
        
        if (x[i] < 0) {
            v = 1;
            x[i] += MOD; 
        }
    }
}

int bigdiv(int *x, int m) {
   int v = 0;
   for (int i = 2 ; i >= 0 ; i--) {
       x[i] += v * MOD;
       v = x[i] % m;
       x[i] /= m;
   } 
   return v;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    bool same = opt<bool>("same");
    int n = opt<int>("n");
    int u = opt<int>("u");
    int v = opt<int>("v");
    
    assert(n > 21);
    assert(!(same && u != v));
    
    cout << u << ' ' << v << endl;
    string s = "";
    for (int i = 0 ; i < n ; i++) {
        int x = rnd.next(i ? 0 : 1, u-1);
        s += '0' + x;
    }
    cout << s << endl;
    if (same) cout << s << endl;
    else {
        for (int i = 0 ; i < n ; i++) {
            cout << rnd.next(i ? 0 : 1, v-1); 
        }
        cout << endl;
    }
}