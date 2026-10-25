//
// Created by Seto on 2025-04-18
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;


void solve()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(auto &i:arr) cin>>i;
  auto minn= min_element(arr.begin(), arr.end());
  auto maxx= max_element(arr.begin(), arr.end());
  cout<<*maxx-*minn<<'\n';
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