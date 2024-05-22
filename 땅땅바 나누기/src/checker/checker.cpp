#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int n;
vector<tuple<int,int,int>> v;

long long readAns(InStream& stream) {
    long long a = stream.readInt(-2000000000, 2000000000, "a");
    long long b = stream.readInt(-2000000000, 2000000000, "b");
    if (a == 0 && b == 0) return -1;
    
    long long u = 0, d = 0;
    
    for (auto [x, y, w] : v) {
        if (a*x > b*y) d += w;
        if (a*x < b*y) u += w;
    }
    
    return min(u, d);
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    n = inf.readInt();
    for (int i = 0; i < n; i++) {
        int x = inf.readInt();
        int y = inf.readInt();
        int w = inf.readInt();
        v.push_back(make_tuple(x,y,w));
    }

    long long jans = readAns(ans);
    long long pans = readAns(ouf);
    if (pans == -1) quitf(_wa, "max(|a|, |b|) must be bigger than 0.");
    if (jans > pans)
        quitf(_wa, "jury has the better answer: jans = %lld, pans = %lld\n", jans, pans);
    else if (jans == pans)
        quitf(_ok, "answer = %lld\n", pans);
    else // (jans < pans)
        quitf(_fail, ":( participant has the better answer: jans = %lld, pans = %lld\n", jans, pans);
}