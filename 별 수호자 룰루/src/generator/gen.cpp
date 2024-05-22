#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n_max = opt<int>("nMax");
    int t_min = opt<int>("tMin");
    bool odd = opt<bool>("odd");
    
    int k = rnd.next(2, n_max/t_min);
    
    if (k == n_max/t_min) {
        if (k%2 != odd) k--;
    }
    else {
        if (k%2 != odd) k++;
    }
    
    int t = rnd.next(t_min, n_max/k);
    
    cout << k*t << ' ' << k << endl;
}