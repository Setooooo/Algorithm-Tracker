//
// Created by Seto on 2025-04-17
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll = long long;
using ull = unsigned long long;
constexpr int maxn=1e3+10;

vector<vector<int>>graph(maxn);
bitset<maxn>vis;
vector<int>match(maxn,-1);

bool xion(int u){
  for(auto i:graph[u]){
    if(vis[i]) continue;
    vis[i]=true;
    if(match[i]==-1||xion(match[i])){
      match[i]=u;
      return true;
    }
  }
  return false;
}


void solve() {
  int n,m; cin>>n>>m;
  vector<pair<int,int>>boy(n),girl(m);
  for(auto &[x,y]:boy) cin>>x>>y;
  for(auto &[x,y]:girl) cin>>x>>y;
  bool f=0;
  for(int i=0;i<n;++i){
    auto &[xs,xe]=boy[i];
    for(int j=0;j<m;++j){
      f=0;
      auto &[ys,ye]=girl[j];
      if(xe>=ys&&xs<=ye) f=1;
      if(f) graph[i].emplace_back(j);
    }
  }
  int ans=0;
  for(int i=0;i<n;++i){
    vis.reset();
    if(xion(i)) ++ans;
  }
  cout<<ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  ifstream file(R"(D:\download\3826.in)");
  cin.rdbuf(file.rdbuf());

  int T = 1;
//    cin>>T;
  while (T--) {
    solve();
  }
}