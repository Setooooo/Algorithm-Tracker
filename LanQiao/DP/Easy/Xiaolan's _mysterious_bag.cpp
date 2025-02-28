//
// Created by beHe on 25-2-28.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
    int n,bag,weight;
    cin>>n>>bag>>weight;
    vector<vector<int>>dp(bag+1,vector<int>(weight+1,0));
    int vol,qua,val;
    for(int i=0;i<n;++i){
        cin>>vol>>qua>>val;
        for(int j=bag;j>=vol;--j)
            for(int k=weight;k>=qua;--k)
                dp[j][k]=max(dp[j][k],dp[j-vol][k-qua]+val);
    }
    cout<<dp[bag][weight];
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