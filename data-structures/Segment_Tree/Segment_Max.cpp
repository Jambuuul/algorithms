struct SegTree {
    int size;
    vector<int> tree;

    void build(vi &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < sz(a)) {
                tree[x] = a[lx];
            }
        } else {
            int m = (lx + rx) / 2;

            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);

            tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
        }

    }

    void build(vector<int> &a) {
        int n = sz(a);
        size = 1 << (__lg(n - 1) + 1);
        tree.assign(2 * size - 1, 0);

        build(a, 0, 0, size);
    }

    void set(int i, int val, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = val;
            return;
        }
        int m = (lx + rx) / 2;

        if (i < m) {
            set(i, val, 2 * x + 1, lx, m);
        } else {
            set(i, val, 2 * x + 2, m, rx);
        }
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(int i, int val) {
        set(i, val, 0, 0, size);
    }

    int maxn(int l, int r, int x, int lx, int rx) {
        if (l >= rx || lx >= r) {
            return INT_MIN;
        }
        if (rx <= r && lx >= l) {
            return tree[x];
        }

        int m = (lx + rx) / 2;

        int min1 = maxn(l, r, 2 * x + 1, lx, m);
        int min2 = maxn(l, r, 2 * x + 2, m, rx);
        return max(min1, min2);
    }

    int maxn(int l, int r) {
        return maxn(l, r, 0, 0, size);
    }
};
