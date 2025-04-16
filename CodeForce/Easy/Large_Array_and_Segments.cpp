//
// Created by beHe on 25-4-15.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
  ll n,k,x; cin>>n>>k>>x;
  vector<ll>pre(n+2,0),arr(n+1);
  for(int i=1;i<=n;++i) cin>>arr[i];
  for(int i=n;i>=1;--i) pre[i]=pre[i+1]+arr[i];
  if(pre[1]*k<x) {
    cout<<0<<'\n';return;
  }
  ll l=1,r=n*k,mid,mo;
  ll res;
  while(l<r){
    mid=(l+r+1)>>1;
    mo=(n*k-mid+1);
    res=pre[1]*(mo/n)+pre[n-mo%n+1];
    if(res>=x)
      l=mid;
    else
      r=mid-1;
  }
  cout<<l<<'\n';
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