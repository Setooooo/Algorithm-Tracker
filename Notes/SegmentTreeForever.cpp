//
// Created by 19233 on 2025/2/1.
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

const int N=1e5+10;


int n,m;
ll arr[N<<2];

void update(int idx,int l,int r,int L,int R,int val)
{
  if(L<=l&&r<=R)
  {
    arr[idx]|=val;
    return;
  }
  int mid=(l+r)>>1;
  if(mid>=R)update(idx<<1,l,mid,L,R,val);
  else if(mid<L)update(idx<<1|1,mid+1,r,L,R,val);
  else{
    update(idx<<1,l,mid,L,mid,val),update(idx<<1|1,mid+1,r,mid+1,R,val);
  }
}

int query(int idx,int l,int r,int pos)
{
  if(l==r)
    return arr[idx];
  int mid=(l+r)>>1;
  if(mid>=pos)return query(idx<<1,l,mid,pos)|arr[idx];
  if(mid<pos) return query(idx<<1|1,mid+1,r,pos)|arr[idx];
}


void solve()
{
  cin>>n>>m;
  int x,y,op,z;
  while (m--)
  {
    cin>>op>>x;
    if(op==1)
    {
      cin>>y>>z;
      update(1,1,n,x,y,z);
    }
    else
    {
      cout<<query(1,1,n,x)<<'\n';
    }
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