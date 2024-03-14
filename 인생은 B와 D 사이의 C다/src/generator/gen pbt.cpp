#include <bits/stdc++.h>
using namespace std;

#define int long long

const string NAME = "randpbt";
const int CASE = 10;

int n, b, d;
int dp[33][111223];

const int MAX = 111222LL*111222LL;

vector<vector<int>> edge;
vector<vector<int>> dedge;

void dfs(int i, int p) {
    for (auto nxt : edge[i]) {
        if (nxt == p) continue;
        dfs(nxt, i);
        dedge[i].push_back(nxt);
    }
}

int foo(int h, int idx) {
    int &ret = dp[h][idx];

    if (ret != -1) return ret;

    if (!h) {
        ret = 0;
        for (auto nxt: dedge[idx]) {
            ret += foo(0, nxt) + d;
        }

        return ret;
    }

    if (!dedge[idx].size()) return ret = b*((1LL<<h+1)-2);
    if (dedge[idx].size() == 1) return ret = b*((1LL<<h)-1) + foo(h-1, dedge[idx][0]);

    int nin1 = MAX, nin2 = MAX;
    auto update = [&](int val) {
        if (val < nin1) nin2 = nin1, nin1 = val;
        else if (val < nin2) nin2 = val;
    };

    int sum = 0;
    for (auto nxt: dedge[idx]) {
        sum += foo(0, nxt) + d;
        update(foo(h-1, nxt) - foo(0, nxt) - d);
    }

    return ret = sum + nin1 + nin2;
}

vector<pair<int, int>> make_tree(int n) {
    random_device rand;
    mt19937 seed(rand());

    vector<pair<int, int>> rtn;
    vector<int> p(n);

    for (int i = 0 ; i < n ; i++) p[i] = i+1;
    shuffle(p.begin(), p.end(), seed);

    for (int i = 1 ; i < n ; i++) {
        uniform_int_distribution<int> gen(0, i-1);
        int j = gen(seed);
        rtn.push_back({p[i], p[j]});
    }

    return rtn;
}

vector<pair<int, int>> make_line(int n) {
    random_device rand;
    mt19937 seed(rand());

    vector<pair<int, int>> rtn;
    vector<int> p(n);

    for (int i = 0 ; i < n ; i++) p[i] = i+1;
    shuffle(p.begin()+1, p.end(), seed);
    for (int i = 1 ; i < n ; i++) {
        rtn.push_back({p[i-1], p[i]});
    }
    
    shuffle(rtn.begin(), rtn.end(), seed);
    return rtn;
}

vector<pair<int, int>> make_star(int n) {
    random_device rand;
    mt19937 seed(rand());

    vector<pair<int, int>> rtn;
    vector<int> p(n);

    for (int i = 0 ; i < n ; i++) p[i] = i+1;
    shuffle(p.begin()+1, p.end(), seed);
    for (int i = 1 ; i < n ; i++) {
        if (i%2) rtn.push_back({1, p[i]});
        else rtn.push_back({p[i], 1});
    }
    
    shuffle(rtn.begin(), rtn.end(), seed);
    return rtn;
}

int cnt;
vector<pair<int, int>> rtn;
vector<int> p;

void pbt(int h, int par) {
    if (h) {
        if (cnt < n-1) {
            rtn.push_back({par, p[++cnt]});
            pbt(h-1, p[cnt]);
        }
        if (cnt < n-1) {
            rtn.push_back({par, p[++cnt]});
            pbt(h-1, p[cnt]);
        }
    }
}

vector<pair<int, int>> make_pbt(int n, int h) {
    random_device rand;
    mt19937 seed(rand());

    rtn = vector<pair<int, int>>();
    p = vector<int>(n);
    cnt = 0;

    for (int i = 0 ; i < n ; i++) p[i] = i+1;
    shuffle(p.begin()+1, p.end(), seed);
    
    pbt(h, p[cnt]);

    shuffle(rtn.begin(), rtn.end(), seed);
    return rtn;
}

signed main() {
    random_device rand;
    mt19937 seed(rand());
    uniform_int_distribution<int> gen(1, 111222);

    for (int case_i = 0 ; case_i < CASE ; case_i++) {
        const string caseName = NAME + to_string(case_i);
        const string inCase = caseName+".in";
        const string outCase = caseName+".out";
        
        uniform_int_distribution<int> ngen(10000, 111221);
        n = 111222;
        vector<pair<int, int>> tree = make_pbt(n, 32);
        
        edge = vector<vector<int>>(n+1);
        dedge = vector<vector<int>>(n+1);

        memset(dp, -1, sizeof(dp));
        b = case_i+1, d = gen(seed);

        freopen(inCase.c_str(), "w", stdout);

        cout << n << ' ' << b << ' ' << d << '\n';
        for (auto ele : tree) {
            int u = ele.first, v = ele.second;
            cout << u << ' ' << v << endl;
            
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        
        int nin = MAX;

        dfs(1, 0);
        for (int i = 0 ; i < 33 ; i++) {
            nin = min(nin, foo(i, 1));
        }
        
        freopen(outCase.c_str(), "w", stdout);
        cout << nin << '\n';
    }
}