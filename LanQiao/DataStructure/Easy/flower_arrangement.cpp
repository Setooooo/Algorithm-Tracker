//
// Created by beHe on 25-2-26.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;
constexpr int N=100;
int memo[N][N],limit[N];

int dfs(int res,int i,int n) {
    if (memo[i][n])
        return memo[res][i];
    if (res==0)
        return memo[i][n]=1;
    for (int j=1;j<=res-(n-i)&&j<=limit[i]&&res-j>=0;++j) {
        memo[res][i]+=dfs(res-j,i+1,n);
    }
    return memo[res][i];
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>limit[i];
    }
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for (int i=0;i<=limit[1];++i)
        dp[1][i]=1;
    for (int i=2;i<=n;++i) {
        for (int j=0;j<=limit[i];++j){}
    }
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