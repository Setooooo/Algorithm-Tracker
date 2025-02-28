//
// Created by 19233 on 2025/2/4.
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

class SegHas{
private:
    int n;
    ull p1,p2;
    string str;
    vector<ull>hash1,hash2;
    vector<ull>base1,base2;
public:
    SegHas(string str,ull _p1=131,ull _p2=1331);
    void build(int idx,int l,int r);
    pair<ull,ull> query(int idx,int l,int r,int L,int R);
    void update(int idx, int l, int r, int pos, int val);
    bool cmp(int l1,int r1,int l2,int r2);
};

SegHas::SegHas(string _str, ull _p1, ull _p2)
        :n(_str.size()-1),p1(_p1),p2(_p2),str((_str))
        ,base1(_str.size(),1),base2(_str.size(),1)
        ,hash1(_str.size()<<2),hash2(_str.size()<<2)
{
  for(int i=1;i<=n;++i)
  {
    base2[i]=base2[i-1]*p2;
    base1[i]=base1[i-1]*p1;
  }
  build(1,0,n);
}

void SegHas::build(int idx, int l, int r) {
  if(l==r)
  {
    hash1[idx]=str[l]-'a'+1;
    hash2[idx]=str[l]-'a'+1;
    return;
  }
  int mid=(l+r)>>1;
  build(idx<<1,l,mid);
  build(idx<<1|1,mid+1,r);
  hash1[idx]=hash1[idx<<1]*base1[r-mid]+hash1[idx<<1|1];
  hash2[idx]=hash2[idx<<1]*base2[r-mid]+hash2[idx<<1|1];
}

pair<ull,ull> SegHas::query(int idx, int l, int r, int L, int R) {
  if(l==L&&r==R)
  {
    return make_pair(hash1[idx],hash2[idx]);
  }
  int mid=(l+r)>>1;
  if(mid>=R) return  query(idx<<1,l,mid,L,R);
    //关于在右区间的查询使用mid<L
  else if(mid<L) return query(idx<<1|1,mid+1,r,L,R);
  else{
    pair<ull,ull>res1= query(idx<<1,l,mid,L,mid),res2= query(idx<<1|1,mid+1,r,mid+1,R);
    return make_pair(res1.first*base1[R-mid]+res2.first,res1.second*base2[R-mid]+res2.second);
  }
}

void SegHas::update(int idx, int l, int r, int pos, int val) {
  if(l==r)
  {
    hash1[idx]=val;
    hash2[idx]=val;
    return;
  }
  int mid=(l+r)>>1;
  if(mid>=pos)update(idx<<1,l,mid,pos,val);
  else update(idx<<1|1,mid+1,r,pos,val);
  //向上传递信息来更新
  hash1[idx]=hash1[idx<<1]*base1[r-mid]+hash1[idx<<1|1];
  hash2[idx]=hash2[idx<<1]*base2[r-mid]+hash2[idx<<1|1];
}

bool SegHas::cmp(int l1, int r1, int l2, int r2) {
  if(query(1,0,n,l1,r1)== query(1,0,n,l2,r2))
    return true;
  return false;
}



void solve()
{
  int n,q;
  cin>>n>>q;
  string str;
  cin>>str;
  SegHas has(str);
  int op,a,b,c,d;
  char cha;
  while (q--)
  {
    cin>>op;
    if(op==1)
    {
      cin>>a>>cha;
      has.update(1,0,n-1,a-1,cha-'a'+1);
    }
    else
    {
      cin>>a>>b>>c>>d;
      //检查区间长度是否一致
      if(b-a!=d-c)
      {
        cout<<"No\n";
        continue;
      }
      int lenpre=0,lenlas=0;
      --a,--b,--c,--d;
      // 修正到0-base
      //计算前缀长度
      {
        int l=0,r=b-a,mid;
        while (l<r)
        {
          mid=(l+r+1)>>1;
          if(has.cmp(a,a+mid,c,c+mid))
            l=mid;
          else
            r=mid-1;
        }
        if(l==0)
        {
          if(has.cmp(a,a,c,c))
            lenpre=1;
          else
            lenpre=0;
        }
        else
          lenpre=l+1;
      }
      // 计算后缀长度
      {
        int l=0,r=b-a,mid;
        while (l<r)
        {
          mid=(l+r+1)>>1;
          // think 1
          if(has.cmp(b-mid,b,d-mid,d))
            l=mid;
          else
            r=mid-1;
        }
        if(l==0)
        {
          if(has.cmp(b,b,d,d))
            lenlas=1;
          else
            lenlas=0;
        }else
        {
          lenlas=l+1;
        }
      }

      if(lenpre+lenlas+1>=b-a+1)
      {
        cout<<"Yes\n";
      }
      else
      {
        cout<<"No\n";
      }
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