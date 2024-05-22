#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int fre = opt<int>("free");
    bool fzero = opt<bool>("fillzero");
    
    ensure(fre + n <= 29);
    
    int k = 0;
    for (int i = 0 ; i < fre ; i++) {
        k <<= 1;
        k += (i ? rnd.next(2) : 1);
    }
    
    for (int i = 0 ; i < n ; i++) {
        k <<= 1;
        k += (fzero ? 0 : rnd.next(2));
    }
    
    cout << n << ' ' << k << endl;
}
