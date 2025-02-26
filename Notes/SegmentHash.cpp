//
// Created by 19233 on 2025/2/2.
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
//https://www.lanqiao.cn/courses/41070/learning/
using namespace std;
using ll=long long;
using ull=unsigned long long;

class StrHash{
private:
    ull p;
    string str;
    int n;
    vector<ull>base,lba;
    vector<ull>fixhash,laze;
public:
    StrHash(const string& str,ull _p=131);
    ull getHash(int idx, int l, int r, int L, int R);
    bool cmp(int l1,int r1,int l2,int r2);
    void build(int idx,int l,int r);
    void update(int idx,int l,int r,int L,int R,int val);
    void pushDown(int idx, int l, int r);
};

StrHash::StrHash(const string& _str, ull _p)
:p(_p),n(_str.size()),str(_str),base(str.size(),1),lba(str.size()+1),fixhash(str.size()<<2,0),laze(str.size()<<2,0) {
  for(int i=1;i<n;++i)
    base[i]=base[i-1]*p;
  for(int i=1;i<=n;++i)
    lba[i]=lba[i-1]*p+1;

  build(1,0,str.size()-1);
}

ull StrHash::getHash(int idx, int l, int r, int L, int R) {
  if(l==L&&r==R)
  {
    return fixhash[idx];
  }
  int mid=(l+r)>>1;
  pushDown(idx,l,r);
  if(mid<L)return getHash(idx<<1|1,mid+1,r,L,R);
  else if(mid>=R)return getHash(idx<<1,l,mid,L,R);
  else{
    return getHash(idx<<1,l,mid,L,mid)*base[R-mid]+getHash(idx<<1|1,mid+1,r,mid+1,R);
  }
}

bool StrHash::cmp(int l1, int r1, int l2, int r2) {
  //这里将修正getHash的查询区间
  //好像不需要修正
  if(getHash(1,0, n-1, l1, r1 ) == getHash(1,0, n-1 ,l2, r2 ))
    return true;
  else
    return false;
}

void StrHash::build(int idx, int l, int r) {
  if(l==r)
  {
    fixhash[idx]=str[l]-'a'+1;
    return;
  }
  int mid=(l+r)>>1;
  build(idx<<1,l,mid);
  build(idx<<1|1,mid+1,r);
  fixhash[idx]=fixhash[idx<<1]*base[r-mid]+fixhash[idx<<1|1];
}

void StrHash::update(int idx, int l, int r, int L, int R, int val) {
  if(l==L&&r==R)
  {
    laze[idx]=val;
    fixhash[idx]=lba[R-L+1]*val;
    return;
  }
  pushDown(idx,l,r);
  int mid=(l+r)>>1;
  if(mid<L)update(idx<<1|1,mid+1,r,L,R,val);
  else if(mid>=R)update(idx<<1,l,mid,L,R,val);
  else{
    update(idx<<1,l,mid,L,mid,val), update(idx<<1|1,mid+1,r,mid+1,R,val);
  }
  fixhash[idx]=fixhash[idx<<1]*base[r-mid]+fixhash[idx<<1|1];
}

void StrHash::pushDown(int idx, int l, int r) {
  //有点莫名其妙加上感叹号
  if(laze[idx])
  {
    int mid=(l+r)>>1;
    laze[idx<<1]=laze[idx<<1|1]=laze[idx];
    fixhash[idx<<1]=lba[mid-l+1]*laze[idx];
    fixhash[idx<<1|1]=lba[r-mid]*laze[idx];
    //忘记了一点没有清除懒标记
    laze[idx]=0;
  }
}

void solve()
{
  int n;
  cin>>n;
  string str;
  cin>>str;
  StrHash has(str);
  int a,b,c,d,op;
  char x;
  int m;
  cin>>m;
  while (m--)
  {
    cin>>op;
    if(op==1)
    {
      cin>>a>>x;
      has.update(1,0,n-1,a,a,x-'a'+1);
    }
    else
    {
      cin>>a>>b>>c>>d;
      cout<<(has.cmp(a-1,b-1,c-1,d-1)?"YES":"NO")<<'\n';
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