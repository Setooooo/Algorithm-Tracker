//
// Created by 19233 on 2025/2/13.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

const int N=1e5+10,LOG=20;
vector<vector<int>>tree(N);
vector<vector<int>>upParent(N,vector<int>(20,0));
vector<int>deep(N,0);

void dfs(int u,int v){
  deep[u]=deep[v]+1;
  upParent[u][0]=v;
  for(int i=1;i<LOG;++i)
    upParent[u][i]=upParent[upParent[u][i-1]][i-1];
  for(const auto i:tree[u])
    if(i!=v)
      dfs(i,u);
}

int LCA(int a,int b)
{
  if(deep[a]<deep[b])swap(a,b);
  for(int i=LOG-1;i>=0;--i)
    if(deep[a]-(1<<i)>=deep[b])
      a=upParent[a][i];
  if(a==b) return a;
  for(int i=LOG-1;i>=0;--i)
    if(upParent[a][i]!=upParent[b][i])
      a=upParent[a][i],b=upParent[b][i];
  return upParent[a][0];
}

int version[N],o;
struct Node{
    int maval,maidx,sl,sr;
    Node():maval(0),maidx(0),sl(0),sr(0){};
}Seg[N*50];


inline void pushUp(int root) {
  int left = Seg[root].sl, right = Seg[root].sr;
  int lval = (left ? Seg[left].maval : 0);
  int rval = (right ? Seg[right].maval : 0);
  int lidx = (left ? Seg[left].maidx : 0);
  int ridx = (right ? Seg[right].maidx : 0);

  if (lval <= 0 && rval <= 0) {
    Seg[root].maval = 0;
    Seg[root].maidx = 0;
  } else if (lval > rval) {
    Seg[root].maval = lval;
    Seg[root].maidx = lidx;
  } else if (rval > lval) {
    Seg[root].maval = rval;
    Seg[root].maidx = ridx;
  } else {
    // 值相等时选择较小的类型编号
    Seg[root].maval = lval;
    Seg[root].maidx = min(lidx, ridx); // 关键修改
  }
}

void update(int &root,int l,int r,int kind,int val)
{
  if(!root)root=++o;
  if(l==r)
  {
    Seg[root].maval+=val;
    Seg[root].maidx=kind;
    return;
  }
  int mid=(l+r)>>1;
  if(mid>=kind)update(Seg[root].sl,l,mid,kind,val);
  else update(Seg[root].sr,mid+1,r,kind,val);
  pushUp(root);
}

void merge(int &left,int right,int l,int r) {
  if (!left) {
    left = right;
    return;
  }
  if (!right) { return; }
  if (l == r)
  {
    Seg[left].maval+=Seg[right].maval;
    return;
  }
  int mid=(l+r)>>1;
  merge(Seg[left].sl,Seg[right].sl,l,mid);
  merge(Seg[left].sr,Seg[right].sr,mid+1,r);
  pushUp(left);
}
int ans[N];

void dfs_merge(int u,int v)
{
  for(const auto i:tree[u])
  {
    if(i!=v)
    {
      dfs_merge(i,u);
      merge(version[u],version[i],1,N);
    }
  }
//  cout<<"this is "<<u<<' '<<'\n', printTree(version[u]);
  ans[u]=Seg[version[u]].maidx;
}

void solve()
{
  int n,m,x,y,z;
  cin>>n>>m;
  for(int i=1;i<n;++i)
    cin>>x>>y,tree[x].emplace_back(y),tree[y].emplace_back(x);
  dfs(1,0);
  for(int i=0;i<m;++i)
  {
    cin>>x>>y>>z;
    int lca=LCA(x,y),plca=upParent[lca][0];
    update(version[x],1,N,z,1),update(version[y],1,N,z,1),update(version[lca],1,N,z,-1),update(version[plca],1,N,z,-1);
  }
  dfs_merge(1,0);
//  for(int i=1;i<=n;++i)
//    printTree(version[i]);
  for(int i=1;i<=n;++i)
    cout<<ans[i]<<'\n';
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