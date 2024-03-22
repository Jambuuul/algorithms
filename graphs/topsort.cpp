    vector<int> order; 
    function<void(int)> dfs = [&](int v) {
        used[v] = 1;
        for (int to : g[v]) {
            if (!used[to]) {
                dfs(to);
            }
        }
        order.pb(v);
    };
    reverse(all(order));
    cout << order;
