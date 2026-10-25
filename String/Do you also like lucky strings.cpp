//
// Created by Seto on 2026-02-05
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
// https://www.lanqiao.cn/courses/41070/learning/?id=2817320&compatibility=false
// 你也喜欢幸运字符串吗
using namespace std;

using ll=long long;
using ull=unsigned long long;


void solve()
{
  int n;string s;cin>>n>>s;
    vector<int> next(n);
    for (int i=1,j=0;i<n;i++) {
        while (j>0&&s[j]!=s[i]) j = next[j-1];
        if (s[i]==s[j])++j;
        next[i] = j;
    }

    vector<ull>dp(n,1);
    for (int i=1;i<n;++i) {
        if (next[i]>0)
        dp[i] = dp[next[i]-1] + 1;
    }
    cout<<accumulate(dp.rbegin(),dp.rend(),0ull)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
//    cin>>T;
    while (T--)
    {
        solve();
    }
}