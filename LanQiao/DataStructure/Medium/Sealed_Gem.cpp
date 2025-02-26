//
// Created by 19233 on 2025/1/26.
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
//https://www.lanqiao.cn/courses/41070/learning/?id=2817416&compatibility=false
using namespace std;
using ll=long long;
using pint = pair<int, int>;
const int N=1e5+10;

struct node{
  pair<int,int>fi,se;
};

node seg[N<<2];
int n,k,arr[N],ans[N];

bool cmp(const pint a,const pint b)
{
  if(a.first==b.first)
    return a.second<b.second;
  else
    return a.first>b.first;
}

void pushUp(int idx)
{
  vector<pair<int,int>>res={seg[idx<<1].fi,seg[idx<<1].se,seg[idx<<1|1].fi,seg[idx<<1|1].se};
  sort(res.begin(),res.end(),cmp);
  seg[idx].fi=res[0];
  seg[idx].se={-1,-1};
  for(int i=1;i<4;++i)
  {
    if(res[i].first==res[0].first)
      continue;
    else
    {
      seg[idx].se=res[i];
      break;
    }
  }
}

void build(int idx,int l,int r)
{
  if(l==r)
  {
    seg[idx].fi={arr[l],l};
    seg[idx].se={-1,-1};
    return;
  }
  int mid=(l+r)>>1;
  build(idx<<1,l,mid);
  build(idx<<1|1,mid+1,r);
  pushUp(idx);
}

void chang(int idx,int l,int r,int pos,int val)
{
  if(l==r)
  {
    seg[idx].fi={-1,-1};
    seg[idx].se={-1,-1};
    return;
  }
  int mid=(l+r)>>1;
  if(mid<pos)chang(idx<<1|1,mid+1,r,pos,val);
  if(mid>=pos)chang(idx<<1,l,mid,pos,val);
  pushUp(idx);
}

vector<pint> query(int idx,int l,int r,int L,int R)
{
  if(L<=l&&r<=R)
  {
    vector<pint>res={seg[idx].fi,seg[idx].se};
    return res;
  }
  int mid=(l+r)>>1;
  vector<pint>leftRes={make_pair(-1,-1),make_pair(-1,-1)};
  vector<pint>rightRes={make_pair(-1,-1), make_pair(-1,-1)};
  if(mid<R) rightRes=query(idx<<1|1,mid+1,r,L,R);
  if(mid>=L)leftRes=query(idx<<1,l,mid,L,R);
  vector<pint>tmp;
  tmp.emplace_back(leftRes[0]);
  tmp.emplace_back(leftRes[1]);
  tmp.emplace_back(rightRes[0]);
  tmp.emplace_back(rightRes[1]);
  sort(tmp.begin(),tmp.end(),cmp);
  vector<pint>result={tmp[0],{-1,-1}};
  for(int i=1; i<4; i++){
    if(tmp[i].first == tmp[0].first) continue;
    result[1] = tmp[i];
    break;
  }
  return result;
}


void solve()
{
  cin>>n>>k;
  for(int i=1;i<=n;++i)
    cin>>arr[i];
  build(1,1,n);
  ans[0]=-2;
  for(int i=1;i<=n;++i)
  {
    auto res= query(1,1,min(n,i+k),i,n);
    if(res[0].first==ans[i-1])
    {
      ans[i]=res[1].first;
      if(ans[i]==-1) {
        continue;
      }
      chang(1,1,n,res[1].second,-1);
      k-=abs(res[1].second-i);
    }
    else
    {
      ans[i]=res[0].first;
      if(ans[i]==-1) {
        continue;
      }
      chang(1,1,n,res[0].second,-1);
      k-=abs(i-res[0].second);
    }
  }
  for(int i=1;i<=n;++i)
    cout<<ans[i]<<' ';
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