#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n_max = opt<int>("nMax");
    
    int k = rnd.next(2, n_max/2);
    int t = rnd.next(2, n_max/k);
    
    cout << k*t << ' ' << k << endl;
}