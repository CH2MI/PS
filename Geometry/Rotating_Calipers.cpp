#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> point;

int CCW(point& a, point& b, point& c) {
    int ans = a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - (b[0] * a[1] + c[0] * b[1] + a[0] * c[1]);
    if (ans > 0) return 1;
    if (ans < 0) return -1;
    return 0;
}

int CCW(point& a, point& b, point& c, point &d) {
    int dx = c[0] - b[0], dy = c[1] - b[1];
    point e = {d[0] - dx, d[0] - dy};
    return CCW(a, b, e);
}

int dist(point& a, point& b) {
    int dx = b[0] - a[0], dy = b[1] - a[1];
    return dx * dx + dy * dy;
}

array<point, 2> calipers(vector<point>& convex) {
    int a = 0, c = 1, l = (int)convex.size();

    point p1 = convex[a], p2 = convex[c];
    int mx = dist(p1, p2);
    while (a < l) {
        int b = (a + 1) % l, d = (c + 1) % l;
        int t = dist(convex[a], convex[c]);
        if (t > mx) {
            p1 = convex[a], p2 = convex[c];
            mx = t;
        }
        if (CCW(convex[a], convex[b], convex[c], convex[d]) < 0) c = (c + 1) % l;
        else a++;
    }
    return {p1, p2};
}
