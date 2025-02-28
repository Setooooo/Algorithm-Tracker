//
// Created by 19233 on 2025/2/6.
//
#include <bits/stdc++.h>
using namespace std;

struct RollbackUF {
    vector<int> parent, rank;
    vector<tuple<int, int, int, int>> stack;

    RollbackUF(int n) : parent(n), rank(n, 1) {
      iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
      while (parent[u] != u) u = parent[u];
      return u;
    }

    bool unite(int u, int v) {
      u = find(u), v = find(v);
      if (u == v) return false;
      if (rank[u] < rank[v]) swap(u, v);
      stack.emplace_back(v, parent[v], u, rank[u]);
      parent[v] = u;
      if (rank[u] == rank[v]) rank[u]++;
      return true;
    }

    void rollback() {
      if (stack.empty()) return;
      auto [v, pv, u, ru] = stack.back();
      stack.pop_back();
      parent[v] = pv;
      rank[u] = ru;
    }
};

struct Edge {
    int u, v, l, r;
    Edge(int u_, int v_, int l_, int r_) : u(u_), v(v_), l(l_), r(r_) {}
};

vector<vector<pair<int, int>>> queries;
vector<string> ans;

void solve(int l, int r, vector<Edge>& edges, RollbackUF& uf) {
  if (l >= r) return;

  int mid = (l + r) / 2;
  vector<Edge> left, right, current;

  for (auto& e : edges) {
    if (e.l <= l && e.r >= r) {
      current.push_back(e);
    } else {
      if (e.l < mid) left.push_back(Edge(e.u, e.v, e.l, e.r));
      if (e.r > mid) right.push_back(Edge(e.u, e.v, e.l, e.r));
    }
  }

  int save = uf.stack.size();
  for (auto& e : current) {
    uf.unite(e.u, e.v);
  }

  if (r - l == 1) {
    for (auto& q : queries[l]) {
      int u = q.first, v = q.second;
      ans.push_back(uf.find(u) == uf.find(v) ? "Y" : "N");
    }
  } else {
    solve(l, mid, left, uf);
    solve(mid, r, right, uf);
  }

  while (uf.stack.size() > save) {
    uf.rollback();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  map<pair<int, int>, int> edge_start;
  vector<Edge> edges;

  queries.resize(M);

  for (int i = 0; i < M; ++i) {
    int type, u, v;
    cin >> type >> u >> v;
    if (u > v) swap(u, v);
    if (type == 1) {
      pair<int, int> p = {u, v};
      if (edge_start.count(p)) {
        int start = edge_start[p];
        edges.emplace_back(u, v, start, i);
        edge_start.erase(p);
      } else {
        edge_start[p] = i;
      }
    } else {
      queries[i].emplace_back(u, v);
    }
  }

  for (auto& [p, start] : edge_start) {
    edges.emplace_back(p.first, p.second, start, M);
  }

  RollbackUF uf(N + 1);

  solve(0, M, edges, uf);

  int idx = 0;
  for (int i = 0; i < M; ++i) {
    if (!queries[i].empty()) {
      cout << ans[idx++] << '\n';
    }
  }

  return 0;
}