#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
int fCnt;
int wei;
vector<int> g;
vector<pair<int,int>> child;

string dfs(int idx, int G) {
    int nowG = (idx < fCnt+1 ? G : rnd.wnext(G+1, wei));
    string s = "";
    for (int i = 0 ; i < nowG ; i++) s += 'g';
    if (idx < fCnt + 1) {
        for (int i = 0 ; i < g[idx] ; i++) s += 'g';
        return s + 'x';
    }
    
    auto [l, r] = child[idx - (fCnt + 1)];
    G -= nowG;
    int leftG = rnd.next(0, G);
    return s + 'f' + dfs(l, leftG) + dfs(r, G - leftG);
}

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    
    int leafMin = opt<int>("leafMin");
    int leafMax = opt<int>("leafMax");
    int fMin = opt<int>("fMin");
    int fMax = opt<int>("fMax");
    int treetype = opt<int>("type");
    int nMax = opt<int>("nMax");
    int wei = opt<int>("wei");
    
    bool nFix = opt<bool>("nFix");
    
    ensure(1<=leafMin && leafMin<=leafMax);
    ensure(fMin<=fMax && 2*fMax+1<=nMax);
    ensure(leafMax*(fMin+1) <= nMax && nMax <= 1'000'000);
    fMax = min(fMax, nMax/leafMax - 1);

    fCnt = rnd.next(fMin, fMax);
    
    g = vector<int>(2*fCnt+1, 0);
    child = vector<pair<int, int>>(fCnt);
    
    int gSum = 0;
    for (int i = 0 ; i < fCnt+1 ; i++) gSum += g[i] = rnd.next(leafMin, leafMax)-1;
    
    vector<int> cardinal(fCnt+1);
    for (int i = 0 ; i < fCnt+1 ; i++) cardinal[i] = i;
    
    vector<int> nonleaf(fCnt);
    for (int i = 0 ; i < fCnt ; i++) nonleaf[i] = i;
    
    shuffle(cardinal.begin(), cardinal.end());
    shuffle(nonleaf.begin(), nonleaf.end());
    
    for (int i = 0 ; i < fCnt ; i++) {
        child[nonleaf[i]] = {cardinal[i*2], cardinal[i*2+1]};
        if (i+1 == fCnt) break;
        cardinal.push_back(nonleaf[i]+fCnt+1);
        if (treetype == 0) // random
            swap(cardinal[i+fCnt], cardinal[rnd.next(i*2+2, i+fCnt)]); 
        else if (treetype == 1) // skew
            swap(cardinal[i+fCnt], cardinal[i*2+2]);
        else if (treetype == 2) // full-binary
            ; // do nothing
        else
            ensure(false);
    }
    
    cout << dfs((fCnt ? nonleaf[fCnt-1] + fCnt + 1 : 0), 
        nFix ? nMax - (gSum + 2*fCnt + 1): rnd.next(0, nMax - (gSum + 2*fCnt + 1))) << endl;
}