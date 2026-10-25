//
// Created by Seto on 2025-04-18
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll = long long;
using ull = unsigned long long;


void solve() {
  int n; cin>>n;
  vector<int>cnt(4,0);
  string a,b;
  cin>>a>>b;
  for(int i=0;i<n;++i){
    if(a[i]=='1'){
      if(i&1) cnt[0]++;
      else cnt[1]++;
    }
    if(b[i]=='0'){
      if(i&1) cnt[2]++;
      else cnt[3]++;
    }
  }
  if(cnt[0]<=cnt[3]&&cnt[1]<=cnt[2])
    cout<<"YES\n";
  else
    cout<<"NO\n";
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