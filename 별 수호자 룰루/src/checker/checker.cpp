#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
 
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    
    int n = inf.readInt(), k = inf.readInt();
    
    string s = ouf.readString("YES|NO");
    if (s == "NO") {
        if (k == 1) quitf(_ok, "ok");
        else if (k == n && n%2) quitf(_ok, "ok");
        else quitf(_wa, "possible case");
    }
    
    vector <bool> perm_test(n+1);
    for (int i = 0 ; i < n/k ; i++) {
        long long sum = 0;
        for (int j = 0 ; j < k ; j++) {
            if(ouf.seekEof()) quitf(_wa, "less outputs"); // 덜 출력한 경우 wa
            int x = ouf.readInt(1, n, "x");
            if(perm_test[x]) quitf(_wa, "not permutation"); // 중복값을 출력한 경우 wa
            perm_test[x] = true;
            sum += x;
        }
        if (sum % k == 0) quitf(_wa, "can divide by k");
    }
    ouf.skipBlanks();
    if(!ouf.seekEof()) quitf(_wa, "more outputs"); // 더 출력한 경우 wa
    quitf(_ok, "ok");
}