#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.size();
    stack<pair<int,int>> stk;
    for (int i = 0 ; i < len ; i++) {
        if (s[i] == 'f') stk.push({0, -1});
        else if (s[i] == 'g') stk.push({1, 0});
        else {
            int x = 0;
            bool psh = false;
            while (!stk.empty()) {
                auto [a, b] = stk.top();
                stk.pop();
                if (!a) {
                    if (b == -1) {
                        stk.push({0, x});
                        psh = true;
                        break;
                    }
                    x = min(x, b);
                }
                else if (a == 1) x++;
                else {
                    stk.push({a, b});
                    break;
                }
            }
            if (!psh) stk.push({2, x});
        }
    }
    if (stk.size() == 1) cout << (stk.top().first == 2 ? stk.top().second : -1) << endl;
    else cout << "-1\n";
}