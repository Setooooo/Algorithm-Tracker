//
// Created by Seto on 2025-04-19
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll = long long;
using ull = unsigned long long;


void solve() {
  int n,las=0,j;
  cin>>n;
  vector<ll>cnt(4,0);
  for(int i=0;i<n;++i) {
    cin>>j;las=max(j,las);
    if(j&1) cnt[0]+=j,cnt[1]++;
    else cnt[2]+=j,cnt[3]++;
  }
  if(!cnt[1]||cnt[1]==n)
    cout<<las<<'\n';
  else
    cout<<cnt[0]+cnt[2]-cnt[1]+1<<'\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
  cin.rdbuf(file.rdbuf());

  int T = 1;
    cin>>T;
  while (T--) {
    solve();
  }
}