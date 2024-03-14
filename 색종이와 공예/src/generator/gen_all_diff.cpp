#include <bits/stdc++.h>
using namespace std;

int N = 1000;
int M = 1000;

int rupt = 0;

const int TC = 10;
const string NAME = "onecol";

char cov[1000][1000];


int main() {
    random_device rand;
    mt19937 seed(rand());
    uniform_int_distribution<int> Ngen(1, 100);
    uniform_int_distribution<int> Mgen(1, 100);

    for (int case_i = 0 ; case_i < TC ; case_i++) {
        const string nowCase = NAME + to_string(case_i);
        const string inCase = nowCase + ".in";
        const string outCase = nowCase + ".out";

        N = 1;
        M = 1000;
    
        freopen(inCase.c_str(), "w", stdout);       
        cout << N << ' ' << M << '\n';

        memset(cov, 0, sizeof(cov));

        uniform_int_distribution<int> gen(0, 25);
        
        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < M ; j++) {
                char c = gen(seed) + 'A';
                while ((i && cov[i-1][j] == c) || (j && cov[i][j-1] == c)) c = gen(seed) + 'A';
                cout << (cov[i][j] = c);
            }
            cout << '\n';
        }

        freopen(outCase.c_str(), "w", stdout);
        cout << "dd\n";
    }
}