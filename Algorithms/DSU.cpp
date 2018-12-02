class DSU {
public:
    vector<int> pt;
    vector<int> wt;
    DSU() {
        int MAX = 100000 + 1;
        pt.resize(MAX);
        wt.resize(MAX);
        for (int i = 0; i < MAX; ++i) {
            pt[i] = i;
            wt[i] = 1;
        }
    }

    int getRoot(int a) {
        while (pt[a] != a) {
            pt[a] = pt[pt[a]];
            a = pt[a];
        }
        return a;
    }

    bool Find(int a, int b) {
        return getRoot(a) == getRoot(b);
    }

    void Union(int a, int b) {
        int root_a = getRoot(a),
          root_b = getRoot(b);
        if (root_a == root_b) return;
        if (wt[root_a] < wt[root_b]) swap(root_a, root_b);
        pt[root_b] = root_a;
        wt[root_a] += wt[root_b];
    }
};
