#include <bits/stdc++.h>
using namespace std;

int n, m;
string s[1000];

bool vis[1000][1000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int csum[26][1001][1001];

bool bfs(int ix, int iy) {
    queue<pair<int, int>> q;
    q.push({ix, iy});

    vis[ix][iy] = true;
    char c = s[ix][iy];

    int xmin = n, xmax = 0, ymin = m, ymax = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        xmin = min(x, xmin);
        xmax = max(x, xmax);
        ymin = min(y, ymin);
        ymax = max(y, ymax);

        for (int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (s[nx][ny] != c || vis[nx][ny]) continue;

            q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }
    
    int sum = csum[c-'A'][xmax+1][ymax+1] + csum[c-'A'][xmin][ymin]; 
    sum -= csum[c-'A'][xmax+1][ymin] + csum[c-'A'][xmin][ymax+1];

    return (xmax-xmin+1)*(ymax-ymin+1) == sum;
}

int main() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) cin >> s[i];

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) csum[s[i][j]-'A'][i+1][j+1] = 1;
    }

    for (int k = 0 ; k < 26 ; k++) {
        for (int i = 0 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) csum[k][i][j] += csum[k][i][j-1];
        }
    }

    for (int k = 0 ; k < 26 ; k++) {
        for (int i = 0 ; i <= m ; i++) {
            for (int j = 1 ; j <= n ; j++) csum[k][j][i] += csum[k][j-1][i];
        }
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (!vis[i][j] && !bfs(i, j)) {
                return cout << "BaboBabo" << endl, 0;
            }
        }
    }

    cout << "dd" << endl;
}