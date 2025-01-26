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
//https://www.lanqiao.cn/courses/41070/learning/?id=2817408&compatibility=false
using namespace std;
using ll=long long;

const int N=2e5+10;
//17.6097   cout<<log(2e5+10)/log(2);

ll prefix[N];
ll mast[N][19],mist[N][19];
int n,q;

void init()
{
  for(int mi=1;(1<<mi)<=n;++mi)
    //think 2
    for(int i=0;i+(1<<mi)-1<=n;++i)
    {
      mast[i][mi]=max(mast[i][mi-1],mast[i+(1<<(mi-1))][mi-1]);
      mist[i][mi]=min(mist[i][mi-1],mist[i+(1<<(mi-1))][mi-1]);
    }
}

ll get(int a,int b,int c,int d)
{
  //think 3
  --a,--b;
  int lenl= log(b-a+1)/ log(2),lenr=log(d-c+1)/log(2);
  //think 1
  ll mi=min(mist[a][lenl],mist[b-(1<<lenl)+1][lenl]),ma=max(mast[c][lenr],mast[d-(1<<lenr)+1][lenr]);
  return ma-mi;
}

void solve()
{
  cin>>n>>q;
  for(int i=1;i<=n;++i)
  {
    cin>>prefix[i];
    prefix[i]+=prefix[i-1];
    mast[i][0]=mist[i][0]=prefix[i];
  }
  init();
  int a,b,c,d;
  while (q--)
  {
    cin>>a>>b>>c>>d;
    cout<<get(a,b,c,d)<<'\n';
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