#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n_min = opt<int>("nMin");
    int n_max = opt<int>("nMax");
    bool impossible = opt<bool>("impossible");
    
    int n = rnd.next(n_min, n_max);
    int e = (!impossible ? rnd.next(0, n-1) : rnd.next(n, 500));
    cout << n << ' ' << e << endl;
}