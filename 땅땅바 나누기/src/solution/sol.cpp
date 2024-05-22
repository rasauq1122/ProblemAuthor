#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

struct Point{
    int x, y, w;
    Point(int a, int b, int c) {
        x = a, y = b, w = c; 
    };
    int dimension() const {
        assert(x || y);
        if (x > 0 && y >= 0) return 1;
        if (x <= 0 && y > 0) return 2;
        if (x < 0 && y <= 0) return 3;
        if (x >= 0 && y < 0) return 4;
        assert(false);
    };
    Point opposite() const {
        return Point(-x, -y, w);
    };
    bool operator<(const Point &p) const {
        int dim = dimension(), pdim = p.dimension();
        if (dim != pdim) return dim < pdim;
        
        int px = p.x, py = p.y;
        return px*y < py*x;
	};
    bool operator==(const Point &p) const {
        int dim = dimension(), pdim = p.dimension();
        if (dim != pdim) return false;
        return p.x*y == p.y*x;
    };
};

signed main() {
    int n;
    cin >> n;

    vector<Point> v;
    for (int i = 0 ; i < n ;i++) {
        int x, y, w;
        cin >> x >> y >> w;
        if (x || y) v.push_back(Point(x, y, w));
    }

    sort(v.begin(), v.end());
    vector<int> psum(1);
    vector<Point> vp;

    bool first = true;
    int len = v.size();
    for (int i = 0 ; i < len ; i++) {
        if (first) {
            psum.push_back(v[i].w);
            vp.push_back(Point(v[i].x, v[i].y, v[i].w));
            first = false;
        }
        else {
            if (vp.back() == v[i]) psum.back() += v[i].w;
            else {
                vp.push_back(Point(v[i].x, v[i].y, v[i].w));
                psum.push_back(psum.back() + v[i].w);
            }
        }
    }

    len = vp.size();
    pair<int, int> nax = make_pair(0, -1);
    for (int i = 0 ; i < len ; i++) {
        int j, u;
        Point opp = vp[i].opposite();
        if (vp[i].dimension() > 2) {
            j = lower_bound(vp.begin(), vp.end(), opp) - vp.begin();
            u = psum.back() - psum[i+1] + psum[j + (vp[j] == opp)];
        }
        else {
            if (vp.back() < opp) u = psum.back() - psum[i+1];
            else {
                j = lower_bound(vp.begin(), vp.end(), opp) - vp.begin();
                u = psum[j + (vp[j] == opp)] - psum[i+1];
            }
        }
        int d = psum.back() - u;
        nax = max(nax, make_pair(min(u, d), i));
    }

    auto [_, idx] = nax;
    // cout << s << endl;
    if (idx == -1) return cout << "1 1\n", 0;

    for (int i = 0 ; i < len ; i++) {
        if (vp[i].dimension() > 2) {
            vp[i] = vp[i].opposite();
        }
    }
    Point p = vp[idx];
    
    vp.push_back(Point(-1, 0, 0));
    sort(vp.begin(), vp.end());

    for (int i = 0 ; i < len ; i++) {
        if (vp[i] == vp[i+1]) continue;
        if (p == vp[i]) {
            return cout << p.y + vp[i+1].y << ' ' << p.x + vp[i+1].x << endl, 0;
        }
    }
}