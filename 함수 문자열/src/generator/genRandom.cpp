#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int nMin = opt<int>("nMin");
    int nMax = opt<int>("nMax");
    ensure(nMin <= nMax && nMax <= 1'000'000);
    
    int n = rnd.next(nMin, nMax);
    string s = "fgx";
    for (int i = 0 ; i < n ; i++) cout << s[rnd.next(2)];
    cout << endl;
}