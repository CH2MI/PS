#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1 << 20;
int arr[sz * 2];

void update(int i, int x) {
    i += sz;
    arr[i] = x;
    while (i > 1) {
        i /= 2;
        arr[i] = arr[i << 1] + arr[i << 1 | 1];
    }
}

int query(int s, int e, int node = 1, int ns = 0, int ne = sz - 1) {
    if (ne < s || e < ns) return 0;
    if (s <= ns && ne <= e) return arr[node];

    int mid = ns + ne >> 1;
    return query(s, e, node << 1, ns, mid) + query(s, e, node << 1 | 1, mid + 1, ne);
}

int main() {
    for (int i = 0; i < 100; i++) update(i, i + 1);

    cout << query(1, 5);
}