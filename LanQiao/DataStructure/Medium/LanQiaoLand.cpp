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
//https://www.lanqiao.cn/courses/41070/learning/?id=2817420&compatibility=false
using namespace std;
using ll=long long;

const int N=2e3+10;
int n,m,q;

struct BIT2D{
    //think 1
    //得不到的就更加爱
    ll tree1[N][N],tree2[N][N],tree3[N][N],tree4[N][N];

    void update(int x,int y,int val)
    {
      for(int i=x;i<=n;i+=i&-i)
        for(int j=y;j<=m;j+=j&-j)
        {
          //think 3
          tree1[i][j]+=val;
          tree2[i][j]+=(y)*val;
          tree3[i][j]+=(x)*val;
          tree4[i][j]+=x*y*val;
        }
    }
    ll query(int x,int y)
    {
      ll ans=0;
      for(int i=x;i>0;i-=i&-i)
        for(int j=y;j>0;j-=j&-j)
        {
          //think 4
          ans+=(x+1)*(y+1)*tree1[i][j]-(x+1)*tree2[i][j]-(y+1)*tree3[i][j]+tree4[i][j];
        }
      return ans;
    }

    ll get_mart(int a,int b,int c,int d)
    {
      // think 2
      return query(c,d)- query(c,b-1)- query(a-1,d)+ query(a-1,b-1);
    }

    void add(int a,int b,int c,int d,int val)
    {
      update(a,b,val), update(a,d+1,-val), update(c+1,b,-val), update(c+1,d+1,val);
    }
};

BIT2D flike;

void solve()
{
  cin>>n>>m>>q;
  int a,b,c,d,val,op;
  ++n,++m;
  while (q--)
  {
    cin>>op>>a>>b>>c>>d;
    if(op==1)
    {
      cin>>val;
      flike.add(a,b,c,d,val);
    }
    else
    {
      cout<<flike.get_mart(a,b,c,d)<<'\n';
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