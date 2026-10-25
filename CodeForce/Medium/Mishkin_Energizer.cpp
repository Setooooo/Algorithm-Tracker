//
// Created by Seto on 2025-04-20
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll = long long;
using ull = unsigned long long;


void solve() {
  string base="LTI";
  ull len;
  string str; cin>>len>> str;
  vector<int>cnt(3,0);
  //计数
  for(int i=0;i<len;++i) {
    if(str[i]=='T') ++cnt[0];
    else if(str[i]=='I') ++cnt[1];
    else ++cnt[2];
  }
  //检查是否可行
  if(count_if(cnt.begin(), cnt.end(),[&](int num){return num==0;})>1) {
    cout<<-1<<'\n'; return;
  }
  vector<int>ans;
  auto op=[&](int idx){
    string res=base; res.erase(res.find(str[idx]),1),res.erase(res.find(str[idx+1]),1);
    ans.emplace_back(idx);
    str=str.substr(0,idx+1)+res[0]+str.substr(idx+1);
  };
  while(1){
    vector<pair<int,char>>vis; vis.reserve(3);
    for(auto i:base) vis.emplace_back(count(str.begin(), str.end(),i),i);
    sort(vis.begin(), vis.end());
    if(vis[0].first==vis[1].first&&vis[1].first==vis[2].first) break;
    bool done=false;
    for(int i=0;i<str.size()-1;++i){
      if(str[i]==str[i+1]) continue;
      if(str[i]!=vis[0].second&&str[i+1]!=vis[0].second){
        op(i),done=true;break;
      }
    }
    if(done) continue;
    for(int i=0;i<str.size()-1;++i){
      if(str[i]==str[i+1]) continue;
      if(str[i]==vis[2].second){
        op(i),op(i),op(i+2),op(i+2); break;
      }else if(str[i+1]==vis[2].second){
        op(i),op(i),op(i+2),op(i+1); break;
      }
    }
  }
  cout<<ans.size()<<'\n';
  for(auto i:ans) cout<<i+1<<'\n';
  if(!ans.empty()) cout<<'\n';
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