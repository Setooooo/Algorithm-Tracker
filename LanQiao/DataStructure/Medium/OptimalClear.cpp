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
//https://www.lanqiao.cn/courses/41070/learning/?id=2817419&compatibility=false
using namespace std;
using ll=long long;

const int N=1e6+10;
int n,k;
struct node{
    int mval,lazy;
};
int nums[N];
//think 2
node arr[N<<2];

void pushUp(int idx)
{
  arr[idx].mval=min(arr[idx<<1].mval,arr[idx<<1|1].mval);
}

void pushDown(int idx)
{
  if(arr[idx].lazy!=0)
  {
    arr[idx<<1].mval+=arr[idx].lazy;
    arr[idx<<1|1].mval+=arr[idx].lazy;
    arr[idx<<1].lazy+=arr[idx].lazy;
    arr[idx<<1|1].lazy+=arr[idx].lazy;

    arr[idx].lazy=0;
  }
}
void build(int idx,int l,int r)
{
  if(l==r){
    arr[idx].mval=nums[l];
    arr[idx].lazy=0;
    return;
  }
  int mid=(l+r)>>1;
  build(idx<<1,l,mid);
  build(idx<<1|1,mid+1,r);
  pushUp(idx);
}

void changeRange(int idx,int l,int r,int L,int R,int val)
{
  if(L<=l&&r<=R)
  {
    arr[idx].mval+=val;
    arr[idx].lazy+=val;
    return;
  }
  pushDown(idx);
  int mid=(l+r)>>1;
  if(mid>=L)changeRange(idx<<1,l,mid,L,R,val);
  if(mid<R)changeRange(idx<<1|1,mid+1,r,L,R,val);
  pushUp(idx);
}

int query(int idx,int l,int r,int L,int R)
{
  if(L<=l&&r<=R){
    return arr[idx].mval;
  }
  pushDown(idx);
  int ans=1e9,mid=(l+r)>>1;
  if(mid>=L)ans=min(ans, query(idx<<1,l,mid,L,R));
  if(mid<R)ans=min(ans, query(idx<<1|1,mid+1,r,L,R));
  return ans;
}

void solve()
{
  cin>>n>>k;
  for(int i=0;i<n;++i)
    cin>>nums[i];
  build(1,0,n-1);
  ll ans=0;
  // think 3
  for(int i=0;i+k-1<=n-1;++i)
  {
    int mival=query(1,0,n-1,i,i+k-1);
    if(mival!=0)
    {
      ans+=mival;
      changeRange(1,0,n-1,i,i+k-1,-mival);
    }
    int val=query(1,0,n-1,i,i);
    if(val==0)
      continue;
    changeRange(1,0,n-1,i,i,-val);
    ans+=val;
  }
  //think 1
  for(int i=n-k+1;i<n;++i)
    ans+= query(1,0,n-1,i,i);
  cout<<ans;
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