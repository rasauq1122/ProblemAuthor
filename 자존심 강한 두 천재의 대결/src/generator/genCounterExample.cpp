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

    bool allow_trivial = !opt<bool>("notTrivial");
    int diff = opt<int>("diff");
    int mLen = opt<int>("mLen");
    
    assert(abs(diff) <= MOD);
    
    int u = rnd.next(2, 10), v = rnd.next(2, 10);
    while (u == v || !(allow_trivial || !(min(u, v) == 2 || MAX[min(u,v)-2][max(u,v)-2] == 1)) || MAX[min(u,v)-2][max(u,v)-2] < mLen) {
        u = rnd.next(2, 10);
        v = rnd.next(2, 10);
    }
    
    int _u = min(u, v), _v = max(u, v);
    int len = rnd.next(max(allow_trivial ? 1 : 2, mLen), MAX[_u-2][_v-2]);
    
    // generate random No. of [min of _v, max of _u]
    int nin[3] = {}, nax[3] = {};
    for (int i = 0 ; i < len ; i++) {
        bigint(nax, _u-1, _u);
        bigint(nin, (i ? 0 : (len == 1 ? 0 : 1)), _v);
    }
    
    if (nax[2] == nin[2] && nax[1] == nin[1]) {
        if (diff < 0) diff = max(diff, nin[0] - nax[0]);
        else diff = min(diff, nax[0] - nin[0]);
    }
    
    bigsub(nax, -min(diff, 0)); 
    bigadd(nin,  max(diff, 0));
    
    int tmp_u[3] = {}, tmp_v[3] = {};
    string us = "", vs = "";
    
    int type = 0;
    
    for (int i = 2 ; i >= 0 ; i--) {
        int x;
        if (type == 0) { // [nin, nax]
            x = rnd.next(nin[i], nax[i]);
            
            if (nin[i] == nax[i]) type = 0;
            else if (nin[i] == x) type = 1;
            else if (nax[i] == x) type = 2;
            else type = 3;
        }
        else if (type == 1) { // [nin, nax)
            x = rnd.next(nin[i], MOD-1);
            
            if (nin[i] == x) type = 1;
            else type = 3;
        }
        else if (type == 2) { // (nin, nax]
            x = rnd.next(0, nax[i]);
            
            if (nax[i] == x) type = 2;
            else type = 3;
        }
        else { // (nin, nax)
            // type == 3 
            x = rnd.next(MOD);    
        }
        
        
        tmp_u[i] = tmp_v[i] = x;
    }
    
    if (diff > 0) bigadd(tmp_v, diff);
    else bigsub(tmp_u, diff);
    
    // cout << nax[2] << ' ' << nax[1] << ' ' << nax[0] << '\n';
    // cout << tmp_u[2] << ' ' << tmp_u[1] << ' ' << tmp_v[0] << '\n';
    // cout << nin[2] << ' ' << nin[1] << ' ' << nin[0] << '\n';
    
    for (int i = 0 ; i < len ; i++) {
        us += '0' + bigdiv(tmp_u, _u);
        vs += '0' + bigdiv(tmp_v, _v);
    }
    
    reverse(vs.begin(), vs.end());
    reverse(us.begin(), us.end());
    
    if (u != _u) swap(vs, us);
    cout << u << ' ' << v << '\n';
    cout << us << '\n' << vs << '\n';
}