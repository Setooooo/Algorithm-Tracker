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
//https://www.lanqiao.cn/courses/41070/learning/?id=2817407&compatibility=false
using namespace std;
using ll=long long;

const int N=1e6+10;
//  cout<<log(N)/log(2); 19.9316

int n,k;
int mist[N][21];

void init()
{
  //think 2
  for(int m=1;(1<<m)<=n;++m)
    //think 3
    for(int i=0;i+(1<<m)<=n;++i)
      //think 1
      mist[i][m]=min(mist[i][m-1],mist[i+(1<<(m-1))][m-1]);
}

int get(int idx){
  int l=max(0,idx-k),r=min(n-1,idx+k);
  int mi=log(r-l+1)/log(2);
  return min(mist[l][mi],mist[r-(1<<mi)+1][mi]);
}

void solve()
{
  cin>>n;
  for(int i=0;i<n;++i)
    cin>>mist[i][0];
  init();
  cin>>k;
  for(int i=0;i<n;++i)
  {
    cout<<get(i)<<' ';
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