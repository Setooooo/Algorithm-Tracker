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
//https://www.lanqiao.cn/courses/41070/learning/?id=2817410&compatibility=false
using namespace std;
using ll=long long;

const int N=5e5+10;
struct node{
    int idx,val;
    node(int i,int v):idx(i),val(v){};
};
int arr[N],dllarge[N],arlarge[N],cllarge[N];
int n;
stack<node>mono;
vector<node>moque;

void solve()
{
  cin>>n;
  for(int i=1;i<=n;++i)
    cin>>arr[i];
  //填充c<d且arr[c]>arr[d]且ab间距小
  for(int i=n;i>0;--i)
  {
    while (!mono.empty()&&mono.top().val<arr[i])
    {
      dllarge[mono.top().idx]=i;
      mono.pop();
    }
    mono.push({i,arr[i]});
  }
  //填充a<b且arr[a]<arr[b]且ab间距小
  while (!mono.empty())mono.pop();
  for(int i=1;i<=n;++i)
  {
    while (!mono.empty()&&mono.top().val<arr[i])
    {
      arlarge[mono.top().idx]=i;
      mono.pop();
    }
    mono.push({i,arr[i]});
  }
  //填充a<c且arr[a]>arr[c]且间距大
  for(int i=1;i<=n;++i)
  {
    int l=0,r=moque.size()-1,mid;
    while (l<r)
    {
      mid=(l+r)>>1;
      if(moque[mid].val<=arr[i])
      {
        l=mid+1;
      }else
      {
        r=mid;
      }
    }
    //think 1
    if(!moque.empty()&&moque[l].val>arr[i])
      cllarge[i]=moque[l].idx;

    if(moque.empty())
      moque.emplace_back(i,arr[i]);
    else if(moque.back().val<arr[i])
      moque.emplace_back(i,arr[i]);
      //如何自定义lowerbound的比较器？
  }
  for(int i=n;i>0;--i)
  {
    //think 2
    if(dllarge[i]
      &&cllarge[dllarge[i]]
      &&arlarge[cllarge[dllarge[i]]]
      &&arlarge[cllarge[dllarge[i]]]<dllarge[i])
    {
      cout<<"YES";
      return;
    }
  }
  cout<<"NO";
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