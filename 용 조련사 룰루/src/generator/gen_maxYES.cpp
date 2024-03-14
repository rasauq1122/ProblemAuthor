#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const string NAME = "maxYES";
const int CASE = 30;

signed main() {
    random_device rand;
    mt19937 seed(rand());
    
    int n = 100;
    uniform_int_distribution<int> ngen(5, 25);
    
    int m = 100;
    
    uniform_int_distribution<int> pgen(1, ((int)1e9) - ((int)1e6));

    for (int case_i = 0 ; case_i < CASE ; case_i++) {
        const string caseName = NAME + to_string(case_i);
        const string inCase = caseName + ".in";
        const string outCase = caseName + ".out";
        freopen(inCase.c_str(), "w", stdout);
        
        n = 1000000;
        // cout << n << ' ' << m << endl;

        vector<int> v;
        for (int i = 0 ; i < n ; i++) v.push_back(pgen(seed));

        int pl = 0;
        sort(v.begin(), v.end());
        for (int i = 1 ; i < n ; i++) {
            v[i] += pl;
            if (v[i-1] == v[i]) v[i]++, pl++;
        }
        
        int nin = max(v[n-2] - v[n-3], v[n-3] - v[n-4]);
        if (n > 1) v[n-1] = min(v[n-2]+m, v[n-1]);

        cout << n << ' ' << nin << endl;
        
        shuffle(v.begin(), v.end(), seed);

        cout << v[0];
        for (int i = 1 ; i < n ; i++) cout << ' ' << v[i];
        cout << endl;

        freopen(outCase.c_str(), "w", stdout);
    }
}