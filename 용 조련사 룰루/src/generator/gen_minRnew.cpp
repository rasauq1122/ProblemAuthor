#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const string NAME = "minRnew";
const int CASE = 30;

signed main() {
    random_device rand;
    mt19937 seed(rand());
    
    int n = 100;
    uniform_int_distribution<int> ngen(1, 4);
    
    int m = 100;
    uniform_int_distribution<int> mgen(1, 33);
    
    uniform_int_distribution<int> pgen(1, 100);

    for (int case_i = 0 ; case_i < CASE ; case_i++) {
        const string caseName = NAME + to_string(case_i);
        const string inCase = caseName + ".in";
        const string outCase = caseName + ".out";
        freopen(inCase.c_str(), "w", stdout);
        
        n = case_i/10 + 3;
        m = mgen(seed);
        cout << n << ' ' << m << endl;

        vector<int> v;
        for (int i = 0 ; i < n ; i++) v.push_back(pgen(seed));

        int pl = 0;
        sort(v.begin(), v.end());
        for (int i = 1 ; i < n ; i++) {
            v[i] += pl;
            if (v[i-1] == v[i]) v[i]++, pl++;
        }

        if (n > 1) v[n-1] = min(v[n-2]+m, v[n-1]);

        shuffle(v.begin(), v.end(), seed);

        cout << v[0];
        for (int i = 1 ; i < n ; i++) cout << ' ' << v[i];
        cout << endl;

        freopen(outCase.c_str(), "w", stdout);
    }
}