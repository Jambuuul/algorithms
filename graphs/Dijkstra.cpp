auto dijkstra = [&](int s) -> void {
        d[s] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> q;

        q.push(mp(0, s));
        while (!q.empty()) {
            auto [tempd, v] = q.top();
            q.pop();
            if (tempd > d[v]) continue;

            for (auto [u, w] : g[v]) {
                if (d[u] > d[v] + w) {
                    d[u] = d[v] + w;
                    q.push(mp(d[u], u));
                }
            }
        }
};
