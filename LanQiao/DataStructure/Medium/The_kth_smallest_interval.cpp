//
// Created by 19233 on 2025/1/30.
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
//https://www.lanqiao.cn/problems/1132/learning/?page=1&first_category_id=1&problem_id=1132
using namespace std;
using ll=long long;

const int N=2e5+10;
int n,m,v;

struct node{
    // think 2
    int ranl,ranr,val,sl,sr;
}seg[N*22];
int arr[N],version[N];
vector<int>soarr;

int bin(int x){
  return lower_bound(soarr.begin(),soarr.end(),x)-soarr.begin();
}
void build(int &idx,int l,int r)
{
  idx=++v;
  seg[idx].ranl=l;
  seg[idx].ranr=r;
  seg[idx].val=0;
  seg[idx].sl=0;
  seg[idx].sr=0;
  if(l==r)
    return;
  int mid=(l+r)>>1;
  // think 3
  build(seg[idx].sl,l,mid);
  build(seg[idx].sr,mid+1,r);
}

void push_Up(int no){
  seg[no].val= seg[seg[no].sl].val + seg[seg[no].sr].val;
}

void insert(int &o,int old,int val)
{
  o=++v;
  seg[o]=seg[old];
  if(seg[o].ranl == seg[o].ranr)
  {
    ++seg[o].val;
    return;
  }
  int mid=(seg[o].ranl + seg[o].ranr) >> 1;
  //think 1
  if(mid>=val)
    insert(seg[o].sl, seg[old].sl, val);
  else
    insert(seg[o].sr, seg[old].sr, val);
  push_Up(o);
}

int query(int now,int old,int k)
{
  if(seg[now].ranl == seg[now].ranr)
  {
    //think 4
    return seg[now].ranl;
  }
  int sumleft= seg[seg[now].sl].val - seg[seg[old].sl].val;
  if(sumleft>=k)
    return query(seg[now].sl, seg[old].sl, k);
  else
    return query(seg[now].sr, seg[old].sr, k - sumleft);
}

void solve()
{
  cin>>n>>m;
  for(int i=1;i<=n;++i)
    cin>>arr[i],soarr.emplace_back(arr[i]);
  sort(soarr.begin(),soarr.end());
  soarr.resize(unique(soarr.begin(), soarr.end())-soarr.begin());
  //think 5
  int cnt=soarr.size();
  build(version[0],0,cnt-1);
  for(int i=1;i<=n;++i)
  {
    insert(version[i],version[i-1], bin(arr[i]));
  }
  int a,b,c;
  while (m--)
  {
    cin>>a>>b>>c;
    cout<<soarr[query(version[b],version[a-1],c)]<<'\n';
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