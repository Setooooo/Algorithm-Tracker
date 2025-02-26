//
// Created by 19233 on 2025/2/6.
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
//https://www.lanqiao.cn/courses/41070/learning/?id=2817429&compatibility=false
using namespace std;
using ll=long long;
using ull=unsigned long long;

const int N=1e5+10;
int n,k,m,version[N],o;
struct node{
    int val,sl,sr;
}Seg[N*40];
int v[N],s[N];
vector<vector<int>>vis;

void update(int &no, int old, int l, int r, int pos)
{
  no=++o;
  Seg[no]=Seg[old];
  if(l==r)
  {
    ++Seg[no].val;
    return;
  }
  int mid=(l+r)>>1;
  //think 1
  if(mid < pos)
    // think 2
    update(Seg[no].sr, Seg[old].sr, mid + 1, r, pos);
  if(mid >= pos)
    update(Seg[no].sl, Seg[old].sl, l, mid, pos);
  Seg[no].val= Seg[Seg[no].sl].val + Seg[Seg[no].sr].val;
}

int query(int idx,int l,int r,int L,int R)
{
  if(L<=l&&r<=R)
  {
    return Seg[idx].val;
  }
  int mid=(l+r)>>1;
  int res=0;
  if(mid<R)res+= query(Seg[idx].sr,mid+1,r,L,R);
  if(mid>=L)res+= query(Seg[idx].sl,l,mid,L,R);
  return res;
}

void solve()
{
  cin>>n>>k>>m;
  vis.resize(k+1);
  int x;
  for(int i=1;i<=n;++i)
    cin>>x,vis[x].emplace_back(i);
  for(int i=1;i<=k;++i)
    cin>>s[i];
  for(int i=1;i<=k;++i)
  {
    unsigned int len=vis[i].size();
    for(int j=0;j<len;++j)
    {
      if(j-s[i]<0) v[vis[i][j]]=0;
      else v[vis[i][j]] = vis[i][j-s[i]];
    }
  }
  Seg[0].sl=Seg[0].sr=Seg[0].val=0;
  for(int i=1;i<=n;++i)
    update(version[i],version[i-1],0,n,v[i]);
  int l,r,ans=0;
  while (m--)
  {
    cin>>l>>r;
    l=(ans^l),r=(ans^r);
    if(l>r)swap(l,r);
    ans= query(version[r],0,n,0,l-1)- query(version[l-1],0,n,0,l-1);
    cout<<ans<<'\n';
  }
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