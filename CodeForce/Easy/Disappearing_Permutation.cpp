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
  int n; cin>>n;
  vector<int>arr(n+1),query(n);
  for(int i=1;i<=n;++i) cin>>arr[i];
  for(auto &i:query) cin>>i;
  set<int>fix;
  for(auto idx:query){
    fix.emplace(idx),fix.emplace(arr[idx]);
    idx=arr[idx];
    while(fix.find(arr[idx])==fix.end()){
      fix.emplace(arr[idx]),idx=arr[idx];
    }
    cout<<fix.size()<<' ';
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