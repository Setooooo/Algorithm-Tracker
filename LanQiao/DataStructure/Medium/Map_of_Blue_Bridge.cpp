//
// Created by 19233 on 2025/2/5.
//
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <numeric>
#include <set>
#include <cstring>
#include <iomanip>
#include <cstdint>
#include <cmath>
//https://www.lanqiao.cn/courses/41070/learning/?id=2817436&compatibility=false
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int N=1e5+10,M=2e5+10;

class UnionbyRank{
public:
    vector<int>father,rank;
    vector<tuple<int,int>>history;
    int n;
public:
    UnionbyRank(int n_):n(n_),father(n_+1),rank(n_+1,0){
      for(int i=0;i<=n;++i)
        father[i]=i;
    }
    int find(int x);
    void merge(int,int);
    void demerge();
};

int UnionbyRank::find(int x) {
  while (x!=father[x])x=father[x];
  return x;
}
void UnionbyRank::merge(int x, int y) {
  int fx=find(x),fy=find(y);
  if(fx==fy)
  {
    history.emplace_back(-1,-1);
  }
  else
  {
    if(rank[fx]>rank[fy])swap(fx,fy);
    history.emplace_back(fx,rank[fy]);
    father[fx]=fy;
    if(rank[fx]==rank[fy])++rank[fy];
  }
}

void UnionbyRank::demerge() {
  auto &[x,rak]=history.back();
  if(x!=-1)
  {
    rank[father[x]]=rak;
    father[x]=x;
  }
  history.pop_back();
}
int n,m;
vector<tuple<int,int,int>>option;
vector<char>ans;
vector<vector<pair<int,int>>>arr;

void insert(int idx,int l,int r,int L,int R,pair<int,int> edge)
{
  if(L<=l&&r<=R)
  {
    arr[idx].emplace_back(edge);
    return;
  }
  int mid=(l+r)>>1;
  if(mid<R)insert(idx<<1|1,mid,r,L,R,edge);
  if(mid>L)insert(idx<<1,l,mid,L,R,edge);
}


void solve(int idx,int l,int r,UnionbyRank &unio)
{

  int save=0;
  for(const auto &i:arr[idx])
  {
    auto &[u,v]=i;
      unio.merge(u,v);
      ++save;
  }
  if(r-l==1)
  {
    auto &[op,u,v]=option[l];
    if(op==2)
    {
      ans[l]=(unio.find(u)==unio.find(v)?'Y':'N');
    }
  }else{
    int mid=(l+r)>>1;
    solve(idx<<1,l,mid,unio);
    solve(idx<<1|1,mid,r,unio);
  }
  while (save--)
    unio.demerge();
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int op,u,v;
  cin>>n>>m;
  UnionbyRank unio(n);
  map<pair<int,int>,int>vis;
  option.resize(m);
  arr.resize(m<<2);
  ans.resize(m,' ');
  for(int i=0;i<m;++i)
  {
    cin>>op>>u>>v;
    if(u>v)swap(u,v);
    option[i]={op,u,v};
    if(op==1)
    {
      auto it=vis.find({u,v});
      if(it!=vis.end())
      {
        insert(1,0,m,it->second,i, {u,v});
        vis.erase({u,v});
      }
      else{
        vis.insert({{u,v},i});
      }
    }
  }
  for(const auto i:vis)
  {
    insert(1,0,m,i.second,m,i.first);
  }
  solve(1,0,m,unio);
  for(int i=0;i<m;++i)
  {
    auto &[a,b,c]=option[i];
    if(a==2)
      cout<<ans[i]<<'\n';
  }
}