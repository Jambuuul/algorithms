auto ford = [&](int v) {
      d[v] = 0;
      bool any = true;
      for (int i = 0; i < n && any; i++) {
          any = false;
          for (auto[a, b, cost] : edges) {
              if (d[a] < INF) {
                  if (d[b] > d[a] + cost) {
                      d[b] = d[a] + cost;
                      any = true;
                  }
              }
          }
      }
};
