//
// Created by 19233 on 2025/1/25.
//
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <numeric>
#include <set>
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;
using ll=long long;

const int N=2e5+10;
ll vis[N];
ll ans,n;
ll root;
int BIT[N],arr[N];
vector<vector<int>>graph;
ll seg[N<<2];

void build(int a[])
{
  for(int i=1;i<=n;++i)
  {
    for(int j=i;j<=n;j+=j&-j)
      BIT[j]+=a[i];
  }
}

void add(int x,int val)
{
  for(int j=x;j<=n;j+=j&-j)BIT[j]+=val;
}

ll quer(int x)
{
  ll res=0;
  for(int j=x;j>0;j-=j&-j)res+=BIT[j];
  return res;
}

void change(int idx,int l,int r,int val,int id)
{
  if(l==r)
  {
    seg[idx]+=val;
    return;
  }
  int mid=(l+r)>>1;
  if(mid<id)change(idx<<1|1,mid+1,r,val,id);
  if(mid>=id)change(idx<<1,l,mid,val,id);
  seg[idx]=seg[idx<<1]+seg[idx<<1|1];
}

ll segquery(int idx,int l,int r,int L,int R)
{
  if(L<=l&&r<=R)
  {
    return seg[idx];
  }
  ll mid=(l+r)>>1,res=0;
  if(mid<R)res+= segquery(idx<<1|1,mid+1,r,L,R);
  if(mid>=L)res+= segquery(idx<<1,l,mid,L,R);
  return res;
}

void dfs(int u,int pre)
{
  int cnt=0;
  //think 4
  for(int i=arr[u]*2;i<=n;i+=arr[u])
    cnt+=vis[i];
  //think 3
  ans+= quer(n-arr[u]+1)-cnt;
  //think 2
  add(n-arr[u]+1,1);
  ++vis[arr[u]];
  for(const auto i:graph[u])
  {
    if(i==pre)continue;
    dfs(i,u);
  }
  add(n-arr[u]+1,-1);
  vis[arr[u]]=0;
}

void solve()
{
  cin>>n>>root;
  //think 1
  for(int i=1;i<=n;++i)
    cin>>arr[i];
  graph.resize(n+1);
  int x,y;
  for(int i=1;i<n;++i)
  {
    cin>>x>>y;
    graph[y].emplace_back(x);
    graph[x].emplace_back(y);
  }
  dfs(root,0);
  cout<<ans<<'\n';

}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T=1;
  while (T--)
  {
    solve();
  }
}