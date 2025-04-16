//
// Created by beHe on 25-4-13.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
  int n,m,k;
  cin>>n>>m>>k;
  int ans=min(n-m*k,n/(m+1));
  if(n-m*k>k){
    for(int i=0,j=0;i<n;++i,j=(j==ans-1?0:j+1)){
      cout<<j<<' ';
    }
  }else{
    for(int i=0,j=0;i<k*m;++i,j=(j==k-1?0:j+1)){
      cout<<j<<' ';
    }
    for(int i=k*m,j=0;i<n;++i,++j){
      cout<<j<<' ';
    }
  }
  cout<<'\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr),cout.tie(nullptr);

  ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
  cin.rdbuf(file.rdbuf());

  int T=1;
    cin>>T;
  while (T--)
  {
    solve();
  }
}