//
// Created by 19233 on 2025/2/18.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

int memo[110][110][110],arr[110][110];
int n,ans,mid;

inline int check(const int depth,const int left)
{
  if(left<mid&&(depth-1-left)<mid)
    return 2;
  else if(left<mid)
    return 1;
  else
    return 3;
}

deque<tuple<int,int,int>>histroy;

void bfs(int depth,int idx,int val,int left)
{
  histroy.emplace_back(1,1,arr[1][1]);
  for(int i=2;i<=n;++i)
  {
    unsigned int siz=histroy.size();
    while (siz--){
      auto &[x,y,z]=histroy.front();
      histroy.pop_front();
      int flag= check(x,z);
      if()
    }
  }
}




void solve()
{
  cin>>n;
  mid=n/2;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=i;++j)
      cin>>arr[i][j];
  bfs(1,1,arr[1][1],0);
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