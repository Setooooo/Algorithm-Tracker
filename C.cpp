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

using namespace std;
using ll=long long;

const int N=1e6+10;
int tire[N][26],n,root,now,cnt,siz[N];

void add(const string& str,int i,int node)
{
  if(i>=str.size())
    return;
  if(tire[node][str[i]-'a'])
    add(str,i+1,tire[node][str[i]-'a']);
  else
    add(str,i+1,tire[now++][str[i]-'a']);

}


void dfs(int u)
{
  vector<int>res;
}

void solve()
{

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