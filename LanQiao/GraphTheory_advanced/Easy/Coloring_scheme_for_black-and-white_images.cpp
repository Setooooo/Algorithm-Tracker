//
// Created by Seto on 2025-04-17
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll = long long;
using ull = unsigned long long;
constexpr ll p=998244353,maxn=1e5+10;

vector<vector<int>>graph(maxn);
int vis[maxn];

void dfs(int u,int color){
  vis[u]=color;
  for(auto i:graph[u]){
    if(vis[i]!=-1) continue;
    dfs(i,color^1);
  }
}

ll qpow(ll a,ll b){
  ll res=1;
  while(b){
    if(b&1) res=(res*a)%p;a=a*a%p,b>>=1;
  }
  return res;
}

void solve() {
  memset(vis,-1,sizeof(vis));
  int n,m;
  cin>>n>>m;
  int u,v;
  vector<pair<int,int>>ve(m);
  for(int i=0;i<m;++i){
    cin>>ve[i].first>>ve[i].second;
    graph[ve[i].first].emplace_back(ve[i].first);
    graph[ve[i].second].emplace_back(ve[i].second);
  }
  ll ans=0;
  for(int i=1;i<=n;++i){
    if(-1==vis[i]) ++ans,dfs(i,0);
  }
  bool f=1;
  for(const auto &[x,y]:ve){
    if(vis[x]==vis[y]) {
      f=0;break;
    }
  }
  if(f)
    cout<<qpow(2,ans);
  else
    cout<<0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
  cin.rdbuf(file.rdbuf());

  int T = 1;
//    cin>>T;
  while (T--) {
    solve();
  }
}