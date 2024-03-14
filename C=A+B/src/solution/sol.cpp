#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, h = 1, q, cnt[3];
int arr[300000];

int tree[(1<<21)+1][3], lazy[(1<<21)+1][3];
bool reset[(1<<21)+1]; // for array C

string s;
int L[300000][3], R[300000][3];

void push(int col, int idx, int l, int r) {
    if (idx < h) { // push-to-child
        for (auto i : {2*idx, 2*idx+1}) {
            if (col == 2 && reset[idx]) {
                lazy[i][col] = 0;
                tree[i][col] = 0;
                reset[i] = true;
            }
            lazy[i][col] += lazy[idx][col]; 
        }
    }

    if (col == 2) reset[idx] = false;
    tree[idx][col] += (r-l+1)*lazy[idx][col];
    lazy[idx][col] = 0;
}

void upd(int col, int idx, int opL, int opR, int ndL, int ndR, int val) {
    push(col, idx, ndL, ndR);
    // cout << idx << ' ' << ndL << ' ' << ndR << endl;
    if (opR < ndL || ndR < opL) return;
    if (opL <= ndL && ndR <= opR) {
        if (val) lazy[idx][col] += val;
        else {
            assert(col == 2);
            lazy[idx][col] = 0;
            tree[idx][col] = 0;
            reset[idx] = true;
        }

        push(col, idx, ndL, ndR);
        return;
    }

    int mid = (ndL+ndR)/2;
    upd(col, 2*idx, opL, opR, ndL, mid, val);
    upd(col, 2*idx+1, opL, opR, mid+1, ndR, val);
    tree[idx][col] = tree[idx*2][col] + tree[idx*2+1][col];
}

int get(int col, int idx, int opL, int opR, int ndL, int ndR) {
    push(col, idx, ndL, ndR);
    if (opR < ndL || ndR < opL) return 0;
    if (opL <= ndL && ndR <= opR) return tree[idx][col];
    
    int mid = (ndL+ndR)/2;
    return get(col, idx*2, opL, opR, ndL, mid) 
           + get(col, idx*2+1, opL, opR, mid+1, ndR);
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> arr[i];
    while (h < n/3) h <<= 1;
    
    cin >> s;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < 3 ; j++) if (s[i] == 'A'+j) {
            tree[h + cnt[j]][j] = arr[i];
            L[i][j] = R[i][j] = ++cnt[j];
        }
    }

    for (int j = 0 ; j < 3 ; j++) {
        for (int i = n-2 ; i >= 0 ; i--) if (!L[i][j]) L[i][j] = L[i+1][j];
        for (int i = 1 ; i < n ; i++) if (!R[i][j]) R[i][j] = R[i-1][j];  
    }

    // for (int j = 0 ; j < 3 ; j++) {
    //     cout << j << endl;
    //     for (int i = 0 ; i < n ; i++) cout << L[i][j] << ' ';
    //     cout << endl;
    //     for (int i = 0 ; i < n ; i++) cout << R[i][j] << ' ';
    //     cout << endl;
    // }

    for (int i = 0 ; i < n/3 ; i++) tree[i+h][2] -= tree[i+h][0] + tree[i+h][1];
    for (int j = 0 ; j < 3 ; j++) {
        for (int i = h-1 ; i >= 0 ; i--) {
            tree[i][j] = tree[i*2][j] + tree[i*2+1][j];
        } 
    }

    int q;
    cin >> q;
    while (q--) {
        int t, I, J, K;
        cin >> t >> I >> J;
        I--, J--;

        if (t == 1) {
            cin >> K;
            for (int i = 0 ; i < 3 ; i++) {
                int l = L[I][i], r = R[J][i];
                if (!l || !r) continue;
                if (l > r) continue;
                // cout << i << " : " << l << ' ' << r << endl; 

                upd(i, 1, l, r, 1, h, K);
                if (i != 2) upd(2, 1, l, r, 1, h, -K);   
            }
        }
        else if (t == 2) {
            int l = L[I][2], r = R[J][2];
            if (!l || !r) continue;
            if (l > r) continue;
            // cout << l << ' ' << r << endl; 

            upd(2, 1, l, r, 1, h, 0);
        }
        else {
            assert(t == 3);
            int sum = 0;
            for (int i = 0 ; i < 3 ; i++) {
                int l = L[I][i], r = R[J][i];
                if (!l || !r) continue;
                if (l > r) continue;
                // cout << i << " : " << l << ' ' << r; 
                
                if (i != 2) {
                    int now = get(i, 1, l, r, 1, h);
                    // cout << " -> " << now << endl;
                    sum += now;
                }
                else {
                    int A = get(0, 1, l, r, 1, h);
                    int B = get(1, 1, l, r, 1, h);
                    int C = get(2, 1, l, r, 1, h);
                    int now = C + (A+B);
                    // cout << " -> " << now << " = " << C << " + (" << A << "+" << B << ')' << endl;
                    sum += now;
                }
            }

            cout << sum << '\n';
        }
    
        // if (t != 3) {
        //     for (int j = 0 ; j < 3 ; j++) {
        //         cout << 'T' << j << " : ";
        //         for (int i = 1 ; i < 2*h ; i++) cout << tree[i][j] << ' ';
        //         cout << '\n';
        //         cout << 'L' << j << " : ";
        //         for (int i = 1 ; i < 2*h ; i++) cout << lazy[i][j] << ' ';
        //         cout << '\n';
        //     }
        // }
    }
}