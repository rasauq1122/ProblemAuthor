#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int n[2];
int sub[2][100001];
long long d[2][100001];
vector<vector<pair<int,int>>> edge[2];

long long expect, but;

int dfs1(int u, int par, long long dis, int idx) {
    sub[idx][u] = 1;
    d[idx][1] += dis;
    for (auto p: edge[idx][u]) {
        auto [v, w] = p;
        if (v == par) continue;
        sub[idx][u] += dfs1(v, u, dis+w, idx);
    }
    return sub[idx][u];
}

long long dfs2(int u, int par, int all, int idx) {
    long long dis = d[idx][u];
    for (auto p: edge[idx][u]) {
        auto [v, w] = p;
        if (v == par) continue;
        d[idx][v] = d[idx][u] - 1LL*sub[idx][v]*w + 1LL*(all-sub[idx][v])*w;
        dis += dfs2(v, u, all, idx);
    }
    return dis;
}

void input() {
    for (int idx = 0 ; idx < 2 ; idx++) {
        n[idx] = inf.readInt();
        edge[idx] = vector<vector<pair<int,int>>>(n[idx]+1);
        for (int i = 1 ; i < n[idx] ; i++) {
            int a = inf.readInt();
            int b = inf.readInt();
            int c = inf.readInt();
            edge[idx][a].push_back({b, c});
            edge[idx][b].push_back({a, c});
        }
        
        dfs1(1, -1, 0, idx);
        dfs2(1, -1, n[idx], idx);
    }
}

long long readAns(InStream& stream) {
    int u = stream.readInt(1, n[0], "u");
    int v = stream.readInt(1, n[1], "v");
    long long sum = stream.readLong(1, INT64_MAX, "sum");
    
    expect = n[1]*d[0][u] + n[0]*d[1][v] + n[0]*n[1];
    but = sum;
    
    if (expect != but) return -1;
    
    return sum;
}

int main(int argc, char **argv) {
    registerTestlibCmd(argc, argv);
    input();
    
    long long jans = readAns(ans);
    long long pans = readAns(ouf);
    if (pans == -1) 
        quitf(_wa, "incorrect value: expect %lld, but %lld", expect, but);
    else if (jans < pans)
        quitf(_wa, "jury has the better answer: jans = %lld, pans = %lld\n", jans, pans);
    else if (jans == pans)
        quitf(_ok, "answer = %lld\n", pans);
    else // (jans > pans)
        quitf(_fail, ":( participant has the better answer: jans = %lld, pans = %lld\n", jans, pans);
}