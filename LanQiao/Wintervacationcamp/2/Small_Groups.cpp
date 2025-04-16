//
// Created by beHe on 25-4-13.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr int maxn=2e5+10;
vector<int>fa(maxn),du(maxn),siz(maxn,1);
vector<set<int>>midu(maxn);
vector<vector<int>>graph(maxn);
bitset<maxn>vis;

int find(int x){
  if(x!=fa[x]) return fa[x]=find(fa[x]); return x;
}
inline void merge(int x,int y){
  int fx=find(x),fy=find(y);
  if(midu[fx].count(du[x])) midu[fx].erase(du[x]);
  if(midu[fy].count(du[y])) midu[fy].erase(du[y]);
  du[x]++,du[y]++;
  midu[fx].emplace(du[x]),midu[fy].emplace(du[y]);
  if(fx==fy) return ;
  if(siz[fx]<siz[fy]) swap(fx,fy);
  siz[fx]+=siz[fy];
  fa[fy]=fx;
  for(const auto &i:midu[fy]) midu[fx].emplace(i);
  midu[fy].clear();
}


void solve()
{
  int n,m; cin>>n>>m;
  //变数读入还有初始化
  {
    int x,y;
    for(int i=0;i<=n;++i) fa[i]=i;
    for(int i=0;i<m;++i){
      cin>>x>>y;
      graph[x].emplace_back(y),graph[y].emplace_back(x);
      du[x]++,du[y]++;
    }
  }
  //开始从外到内删除节点并记录顺序
  vector<int>order;
  {
    set<pair<ll,int>>res;
    for(int i=1;i<=n;++i) res.emplace(du[i],i);
    while(!res.empty()){
      auto [num,idx]=*res.begin();
      res.erase(res.begin());
      order.emplace_back(idx);
      vis[idx]=true;
      for(const auto &ne:graph[idx]){
        if(vis[ne]) continue;
        res.erase({du[ne],ne});
        if(du[ne]==1){
          order.emplace_back(ne);
//          vis[ne]=true;
        }
        res.emplace(--du[ne],ne);
      }
    }
  }
  //计算答案
  ll ans=0;
  {
    fill(du.begin(),du.begin()+n+1,0);
    vis.reset();
    for (auto it = order.rbegin(); it != order.rend(); ++it) {
      auto &idx = *it;
      vis[idx] = true;
      for (auto i: graph[idx]) {
        if (!vis[i]) continue;
        merge(idx, i);
      }
      int fdi = find(idx);
      if (!midu[fdi].empty()) ans=max(ans,1LL*siz[fdi]*(*midu[fdi].begin()));
    }
  }
  cout<<ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr),cout.tie(nullptr);

  ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
  cin.rdbuf(file.rdbuf());

  int T=1;
//    cin>>T;
  while (T--)
  {
    solve();
  }
}