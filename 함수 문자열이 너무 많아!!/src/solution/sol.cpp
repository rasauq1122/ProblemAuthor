#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long

int dp[2002][1001];
int psum[2002][1002];

int foo(int n, int t) {
    int &ret = dp[n][t];
    if (ret) return ret;
    if (n == t+1) {
        psum[n][t+1] = psum[n][t] + 1;
        return ret = 1;
    }

    if (n < t+1) return ret = 0;
    if (n > 1 && t > 0) ret += foo(n-1, t-1);
    if (n > 2*t + 2) {
        // case 1. eval(L) = eval(R) = t
        for (int len = t+1 ; len <= n-1-(t+1) ; len++) { 
            int l = foo(len, t), r = foo(n-1-len, t);
            ret += (l * r) % MOD;
            ret %= MOD;
        }

        // case 2. eval(L) > eval(R) = t
        int tmp = 0;
        for (int len = t+2 ; len <= n-1-(t+1) ; len++) {
            int r = foo(n-1-len, t);
            int l = (psum[len][min(len-1,n-t-2)+1] - psum[len][t+1] + MOD)%MOD;
            tmp += (2 * l * r)%MOD;
            tmp %= MOD;
        }

        ret += tmp;
        ret %= MOD;
    }
    
    psum[n][t+1] = (psum[n][t] + ret)%MOD;
    return ret;
}

signed main() {
    int n, e;
    cin >> n >> e;
    for (int len = 1 ; len < n ; len++) {
        for (int eval = 0 ; eval < len ; eval++) foo(len, eval);
    } 
    cout << foo(n, e) << endl;
}