#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int k = rnd.next(1, 1'000'000'000);
    cout << n << ' ' << k << endl;
}
