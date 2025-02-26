//
// Created by 19233 on 2025/2/18.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

int arr[110][110];

void solve()
{
  //think 2
  int n,x,ans=0;
  cin>>n;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=i;++j)
    {
      cin>>arr[i][j];
    }
  for(int i=1;i<=n;++i)
  {
    for(int j=1;j<=i;++j)
    {
      if(j==1)
        //think 1
        arr[i][j]+=arr[i-1][j];
      else if(j==i)
        arr[i][j]+=arr[i-1][j-1];
      else
        arr[i][j]+=max(arr[i-1][j],arr[i-1][j-1]);
    }
  }
  if(n&1){
    cout<<arr[n][n/2+1];
  }else{
    cout<<max(arr[n][n/2],arr[n][n/2]);
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