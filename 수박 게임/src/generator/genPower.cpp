#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    ensure(n <= 28);
    int r = opt<int>("r");
    
    int k = 1<<n-1;
    ensure(1 <= k + r && k + r <= 1'000'000'000);
    
    k += r;
    
    cout << n << ' ' << k << endl;
}