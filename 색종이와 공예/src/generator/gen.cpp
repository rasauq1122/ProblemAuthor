#include <bits/stdc++.h>
using namespace std;

int N = 1000;
int M = 1000;

int rupt = 0;
int wei = 1000;

const int TC = 20;
const string NAME = "dd_small";

int idx[1001][1001], now_i;
int dat[1000*1000][4];
char abc[1000*1000];
char cov[1001][1001];

void f(int sx, int sy, int ex, int ey) {
    if (sx > ex || sy > ey || sx >= N || sy >= M) return;
    random_device rand;
    mt19937 seed(rand());
    uniform_int_distribution<int> gen(1, N*M);

    int w = ex - sx + 1;
    int h = ey - sy + 1;

    int lb = gen(seed);
    if (w*h <= wei && lb <= N*M+1-w*h) {
        idx[sx][sy] += now_i;
        idx[sx][ey+1] -= now_i;
        idx[ex+1][sy] -= now_i;
        idx[ex+1][ey+1] += now_i; 

        dat[now_i][0] = sx;
        dat[now_i][1] = sy;
        dat[now_i][2] = ex;
        dat[now_i][3] = ey;

        now_i++;

        return;
    }

    int x1, x2, y1, y2;

    if (w == 1) {
        uniform_int_distribution<int> ygen(sy, ey);
        y1 = ygen(seed), y2 = ygen(seed);
        if (y1 > y2) swap(y1, y2);

        f(sx, sy, ex, y1);
        f(sx, y1+1, ex, y2);
        f(sx, y2+1, ex, ey);
    }
    else if (h == 1) {
        uniform_int_distribution<int> xgen(sx, ex);
        x1 = xgen(seed), x2 = xgen(seed);
        if (x1 > x2) swap(x1, x2);

        f(sx, sy, x1, ey);
        f(x1+1, sy, x2, ey);
        f(x2+1, sy, ex, ey);
    }
    else {
        uniform_int_distribution<int> xgen(sx, ex);
        x1 = xgen(seed), x2 = xgen(seed);
        if (x1 > x2) swap(x1, x2);

        uniform_int_distribution<int> ygen(sy, ey);
        y1 = ygen(seed), y2 = ygen(seed);
        if (y1 > y2) swap(y1, y2);

        uniform_int_distribution<int> tgen(0, 11);
        int type = tgen(seed);
        
        //   0     1     2     3     4     5     6     7     8     9     10    11
        //  AAB | ABB | ABB | ABB | AAA | ABD | AAB | ABD | AAA | AAB | AAA | ABD
        //  CEB | AED | AED | AED | CEB | AED | CEB | AED | CEB | CEB | CEB | AED
        //  CDD | CCD | CCC | ACD | DDB | CCD | DDD | ACC | CDD | CDB | DDD | ACD

        switch (type) {
            case 0:
            f(sx, sy, x1, y2);
            f(sx, y2+1, x2, ey);
            f(x1+1, sy, ex, y1);
            f(x2+1, y1+1, ex, ey);
            f(x1+1, y1+1, x2, y2);
            break;

            case 1:
            f(sx, sy, x2, y1);
            f(sx, y1+1, x1, ey);
            f(x2+1, sy, ex, y2);
            f(x1+1, y2+1, ex, ey);
            f(x1+1, y1+1, x2, y2);
            break;

            case 2:
            f(sx, sy, x2, y1);
            f(sx, y1+1, x1, ey);
            f(x2+1, sy, ex, ey);
            f(x1+1, y2+1, x2, ey);
            f(x1+1, y1+1, x2, y2);
            break;

            case 3:
            f(sx, sy, ex, y1);
            f(sx, y1+1, x1, ey);
            f(x2+1, y1+1, ex, y2);
            f(x1+1, y2+1, ex, ey);
            f(x1+1, y1+1, x2, y2);
            break;

            case 4:
            f(sx, sy, x1, ey);
            f(x1+1, y2+1, ex, ey);
            f(x1+1, sy, x2, y1);
            f(x2+1, sy, ex, y2);
            f(x1+1, y1+1, x2, y2);
            break;

            case 5:
            f(sx, sy, x2, y1);
            f(sx, y1+1, x1, y2);
            f(x2+1, sy, ex, y2);
            f(sx, y2+1, ex, ey);
            f(x1+1, y1+1, x2, y2);
            break;

            case 6:
            f(sx, sy, x1, y2);
            f(sx, y2+1, x2, ey);
            f(x1+1, sy, x2, y1);
            f(x2+1, sy, ex, ey);
            f(x1+1, y1+1, x2, y2);
            break;

            case 7:
            f(sx, sy, ex, y1);
            f(sx, y1+1, x1, y2);
            f(x2+1, y1+1, ex, ey);
            f(sx, y2+1, x2, ey);
            f(x1+1, y1+1, x2, y2);
            break;

            case 8:
            f(sx, sy, x1, ey);
            f(x1+1, y2+1, x2, ey);
            f(x1+1, sy, ex, y1);
            f(x2+1, y1+1, ex, ey);
            f(x1+1, y1+1, x2, y2);
            break;

            case 9:
            f(sx, sy, x1, y2);
            f(sx, y2+1, ex, ey);
            f(x1+1, sy, ex, y1);
            f(x2+1, y1+1, ex, y2);
            f(x1+1, y1+1, x2, y2);
            break;

            case 10:
            f(sx, sy, x1, ey);
            f(x1+1, y2+1, x2, ey);
            f(x1+1, sy, x2, y1);
            f(x2+1, sy, ex, ey);
            f(x1+1, y1+1, x2, y2);
            break;

            case 11:
            f(sx, sy, ex, y1);
            f(sx, y1+1, x1, y2);
            f(x2+1, y1+1, ex, y2);
            f(sx, y2+1, ex, ey);
            f(x1+1, y1+1, x2, y2);
            break;
        }
    }
}

int main() {
    random_device rand;
    mt19937 seed(rand());
    uniform_int_distribution<int> Ngen(1, 100);
    uniform_int_distribution<int> Mgen(1, 100);

    for (int case_i = 0 ; case_i < TC ; case_i++) {
        const string nowCase = NAME + to_string(case_i);
        const string inCase = nowCase + ".in";
        const string outCase = nowCase + ".out";

        N = Ngen(seed);
        M = Mgen(seed);
    
        wei = max(N, M);
        
        uniform_int_distribution<int> rgen(1, N*M);
        // rupt = rgen(seed);

        freopen(inCase.c_str(), "w", stdout);       
        cout << N << ' ' << M << '\n';

        now_i = 0;
        memset(idx, 0, sizeof(idx));
        memset(dat, 0, sizeof(dat));
        memset(abc, 0, sizeof(abc));
        memset(cov, 0, sizeof(cov));

        f(0, 0, N-1, M-1);

        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < M ; j++) idx[i][j+1] += idx[i][j];
        }
        for (int j = 0 ; j < M ; j++) {
            for (int i = 0 ; i < N ; i++) idx[i+1][j] += idx[i][j];
        }

        for (int i = 0; i < N ; i++) {
            for (int j = 0 ; j < M ; j++) {
                int k = idx[i][j];
                if (abc[k]) continue;

                int sx = dat[k][0], sy = dat[k][1], ex = dat[k][2], ey = dat[k][3];
                int bit = (1<<26)-1;
                if (sx) {
                    for (int y = sy ; y <= ey ; y++) {
                        int now = idx[sx-1][y];
                        if (abc[now]) {
                            if (bit & 1<<abc[now]-'A') bit ^= 1<<abc[now]-'A';
                        }
                    }
                }
                if (ex+1 < N) {
                    for (int y = sy ; y <= ey ; y++) {
                        int now = idx[ex+1][y];
                        if (abc[now]) {
                            if (bit & 1<<abc[now]-'A') bit ^= 1<<abc[now]-'A';
                        }
                    }
                }
                if (sy) {
                    for (int x = sx ; x <= ex ; x++) {
                        int now = idx[x][sy-1];
                        if (abc[now]) {
                            if (bit & 1<<abc[now]-'A') bit ^= 1<<abc[now]-'A';
                        }
                    }
                }
                if (ey+1 < M) {
                    for (int x = sx ; x <= ex ; x++) {
                        int now = idx[x][ey+1];
                        if (abc[now]) {
                            if (bit & 1<<abc[now]-'A') bit ^= 1<<abc[now]-'A';
                        }
                    }
                }

                string s = "";
                int len = 0;
                for (int i = 0 ; i < 26 ; i++) {
                    if (bit & 1<<i) len++, s += (char)('A'+i);
                }

                uniform_int_distribution<int> sgen(0,len-1);
                abc[k] = s[sgen(seed)];
            }
        }
        
        uniform_int_distribution<int> xgen(0, N-1);
        uniform_int_distribution<int> ygen(0, M-1);
    
        for (int i = 0 ; i < rupt ; i++) {
            int x = xgen(seed), y = ygen(seed);

            int bit = (1<<26)-1;
            int dx[4] = {1, -1, 0, 0};
            int dy[4] = {0, 0, 1, -1};

            for (int j = 0 ; j < 4 ; j++) {
                int nx = x + dx[j], ny = y + dy[j];

                if (nx <= 0 || ny <= 0 || nx >= N || ny >= M) continue;
                if (bit & 1<<abc[idx[nx][ny]]-'A') bit ^= 1<<abc[idx[nx][ny]]-'A';
            }

            string s = "";
                int len = 0;
                for (int i = 0 ; i < 26 ; i++) {
                    if (bit & 1<<i) len++, s += (char)('A'+i);
                }

                uniform_int_distribution<int> sgen(0,len-1);
                cov[x][y] = s[sgen(seed)];
        }

        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < M ; j++) {
                if (cov[i][j]) cout << cov[i][j];
                else cout << abc[idx[i][j]];
            }
            cout << '\n';
        }

        freopen(outCase.c_str(), "w", stdout);
        cout << "dd\n";
    }
}