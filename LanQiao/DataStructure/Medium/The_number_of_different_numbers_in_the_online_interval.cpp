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
//https://www.lanqiao.cn/problems/8461/learning/?page=1&first_category_id=1&problem_id=8461
using namespace std;
using ll=long long;

const int N=1e5+10;
struct node{
    int sl,sr,val;
}seg[N*30];
int n,q,v;
int arr[N],lastarr[N],version[N];

void build(int &o,int l,int r)
{
  o=++v;
  seg[o].sl=0;
  seg[o].sr=0;
  seg[o].val=0;
  if(l==r){
    return;
  }
  int mid=(l+r)>>1;
  build(seg[o].sl,l,mid);
  build(seg[o].sr,mid+1,r);
}

void insert(int &o,int pre,int l,int r,int pos)
{
  o=++v;
  seg[o]=seg[pre];
  if(l==r)
  {
    ++seg[o].val;
    return;
  }
  int mid=(l+r)>>1;
  // think 4
  if(mid>=pos)insert(seg[o].sl,seg[pre].sl,l,mid,pos);
  else insert(seg[o].sr,seg[pre].sr,mid+1,r,pos);
  seg[o].val=seg[seg[o].sl].val+seg[seg[o].sr].val;
}

//think 2
int query(int now, int old, int be, int l, int r)
{
  //think 1
  if(0<=l&&r<=be)
  {
    // think 3
    return seg[now].val-seg[old].val;
  }
  int mid=(l+r)>>1;
  int cnt=0;
  if(mid<be)cnt+= query(seg[now].sr,seg[old].sr, be, mid + 1, r);
  if(mid>=0)cnt+= query(seg[now].sl,seg[old].sl, be,   l,   mid);
  return cnt;
}

void solve()
{
  cin>>n>>q;
  build(version[0],0,n);
  for(int i=1;i<=n;++i)
  {
    cin>>arr[i];
    insert(version[i],version[i-1],0,n,lastarr[arr[i]]);
    lastarr[arr[i]]=i;
  }
  int lastans=0,l,r;
  while (q--)
  {
    cin>>l>>r;
    //think 6
    l=(l+lastans)%n+1,r=(r+lastans)%n+1;
    if(l>r)swap(l,r);
    lastans= query(version[r],version[l-1],l-1,0,n);
    cout<<lastans<<'\n';
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