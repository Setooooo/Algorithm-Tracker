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
//https://www.lanqiao.cn/courses/41070/learning/?id=2817409&compatibility=false
using namespace std;
using ll=long long;

const int N=3e5+10;
struct node{
    int idx,val;
};
stack<node>res;
int n;
int arr[N],lmin[N],rmin[N];

void solve()
{
  ll ans=0;
  cin>>n;
  for(int i=1;i<=n;++i)
    cin>>arr[i];
  for(int i=1;i<=n;++i)
  {
    while (!res.empty()&&res.top().val>arr[i])
    {
      lmin[res.top().idx]=i;
      res.pop();
    }
    res.push({i,arr[i]});
  }
  while (!res.empty())
  {
    lmin[res.top().idx]=n+1;
    res.pop();
  }
  for(int i=n;i>0;--i)
  {
    while (!res.empty()&&res.top().val>arr[i])
    {
      rmin[res.top().idx]=i;
      res.pop();
    }
    res.push({i,arr[i]});
  }
  while (!res.empty())
  {
    rmin[res.top().idx]=0;
    res.pop();
  }
  for(int i=1;i<=n;++i)
  {
    ans=max(ans,1LL*arr[i]*(lmin[i]-rmin[i]-1));
  }
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