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
//题目说要我完成操作完成后的序列，但是我却在想操作之后每次输出交换的次数，导致想了很久没相通
//终于在昏昏欲睡里明白这个线段树在做什么？
//https://www.lanqiao.cn/courses/41070/learning/?id=2817418&compatibility=false
const int N=1e5+10;
struct node{
    int id,sum,lazy;
};
node seg[N<<2];

void build(int idx,int l,int r)
{
  // think 1
  auto &now=seg[idx];
  if(l==r){
    now.id=l;
    now.lazy=-1;
    now.sum=1;
    return;
  }
  int mid=(l+r)>>1;
  build(idx<<1,l,mid);
  build(idx<<1|1,mid+1,r);
  now.sum=seg[idx<<1].sum+seg[idx<<1|1].sum;
  now.lazy=-1;
}

void pushDown(int idx,int l,int r)
{
  auto &now=seg[idx];
  if(now.lazy!=-1)
  {
    int mid=(l+r)>>1;
    int lenl=mid-l+1,lenr=r-mid;

    seg[idx<<1].sum=lenl*now.lazy;
    seg[idx<<1|1].sum=lenr*now.lazy;

    now.sum=seg[idx<<1].sum+seg[idx<<1|1].sum;
    seg[idx<<1].lazy=now.lazy;
    seg[idx<<1|1].lazy=now.lazy;
    now.lazy=-1;
  }
}
//减去1的数量为cnt
void RechangeRange(int idx, int l, int r, int cnt)
{
  if(cnt==0)
  {
    return;
  }
  if(cnt==seg[idx].sum)
  {
    seg[idx].sum=0;
    seg[idx].lazy=0;
    return;
  }
  pushDown(idx,l,r);
  int lsum=seg[idx<<1].sum;
  int mid=(l+r)>>1;
  if(cnt<=lsum)
  {
    RechangeRange(idx << 1, l, mid, cnt);
  }
  else
  {
    RechangeRange(idx << 1, l, mid, lsum);
    RechangeRange(idx << 1 | 1, mid + 1, r, cnt - lsum);
  }
  seg[idx].sum-=cnt;
}
//添加1
void AddchangeRange(int idx,int l,int r,int cnt)
{
  if(cnt==0)
    return;
  int len=r-l+1;
  if(len-seg[idx].sum==cnt)
  {
    seg[idx].sum=len;
    seg[idx].lazy=1;
    return;
  }
  pushDown(idx,l,r);
  int lsum=seg[idx<<1].sum;
  int mid=(l+r)>>1;
  int lenl=mid-l+1;
  if(cnt<=lenl-lsum)
  {
    //think 3
    AddchangeRange(idx<<1,l,mid,cnt);
  }
  else
  {
    AddchangeRange(idx<<1,l,mid,lenl-lsum);
    AddchangeRange(idx<<1|1,mid+1,r,cnt-lenl+lsum);
  }
  seg[idx].sum+=cnt;
}

int query(int idx,int l,int r,int L,int R)
{
  if(L>r||R<l)return 0;
  if(L<=l&&r<=R)
  {
    return seg[idx].sum;
  }
  pushDown(idx,l,r);
  int mid=(l+r)>>1,res=0;
  if(mid>=L)res+= query(idx<<1,l,mid,L,R);
  //think 2
  if(mid<R)res+= query(idx<<1|1,mid+1,r,L,R);
  return res;
}

int n,m;

void solve()
{
  cin>>n>>m;
  build(1,1,n);
  int op,pos,allone=n;
  while (m--)
  {
    cin>>op>>pos;
    if(op==1) {
      allone = query(1, 1, n, 1, n);
      if (n - pos + 1 > allone)
      {
        AddchangeRange(1,1,n,n-pos+1-allone);
      }
    }
    else
    {
      allone= query(1,1,n,1,n);
      if(n-allone<pos)
      {
        RechangeRange(1,1,n,pos-n+allone);
      }
    }
  }
  vector<int>res1,res2;
  for(int i=1;i<=n;++i)
    if(query(1,1,n,i,i)==1)
      res2.emplace_back(i);
  for(int i=n;i>0;--i)
    if(query(1,1,n,i,i)==0)
      res1.emplace_back(i);
  for(const auto i:res1)
    cout<<i<<' ';
  for(const auto i:res2)
    cout<<i<<' ';
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