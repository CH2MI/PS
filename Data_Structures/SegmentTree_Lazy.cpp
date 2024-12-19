#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 20;
int arr[sz * 2], lazy[sz * 2];

void propagate(int node, int ns, int ne) {
    if (!lazy[node]) return;
    if (node < sz) {
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
    }
    arr[node] += lazy[node] * (ne - ns + 1);
    lazy[node] = 0;
}

void update(int s, int e, int k, int node = 1, int ns = 0, int ne = sz - 1) {
    propagate(node, ns, ne);

    if (ne < s || e < ns) return;
    if (s <= ns && ne <= e) {
        lazy[node] += k;
        propagate(node, ns, ne);
        return;
    }

    int mid = ns + ne >> 1;
    update(s, e, k, node << 1, ns, mid), update(s, e, k, node << 1 | 1, mid + 1, ne);
    arr[node] = arr[node << 1] + arr[node << 1 | 1];
}

int query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    propagate(node, ns, ne);

    if (ne < s || e < ns) return 0;
    if (s <= ns && ne <= e) return arr[node];

    int mid = ns + ne >> 1;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}