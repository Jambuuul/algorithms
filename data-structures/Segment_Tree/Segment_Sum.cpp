struct SegTree {

    int size;
    vector<int> tree;

    void build(vector<int>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) tree[x] = a[lx];
        }else {
            int m = (lx + rx) / 2;

            build(a, 2 * x + 1, lx, m);
            build(a, 2 * x + 2, m, rx);

            tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        }
    }

    void build(vector<int> &a) {
        size = 1 << (__lg(sz(a) - 1) + 1);
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
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }


    void set(int i, int val) {
        set(i, val, 0, 0, size);
    }

    int sum(int l, int r, int x, int lx, int rx) {
        if (l >= rx || lx >= r) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            return tree[x];
        }
        int m = (lx + rx) / 2;

        int s1 = sum(l, r, 2 * x + 1, lx, m);
        int s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }

    int sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};
