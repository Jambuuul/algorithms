int n, m;
vector<string> a;
vector<vector<int>> used;
 
vector<int> dy {1, 0, -1, 0};
vector<int> dx {0, 1, 0, -1};
 
void bfs(int ti, int tj) {
    queue<pair<int, int>> q;
    q.push(mp(ti, tj));
 
    used[ti][tj] = 1;
    while (!q.empty()) {
        auto& [i, j] = q.front();
        q.pop();
 
        for (int t = 0; t < 4; t++) {
            int ty = i + dy[t];
            int tx = j + dx[t];
 
            if (ty >= 0 && ty < n && tx >= 0 && tx < m &&
                !used[ty][tx] && a[ty][tx] == '*') {
                q.push(mp(ty, tx));
                used[ty][tx] = 1;
            }
        }
    }
}
