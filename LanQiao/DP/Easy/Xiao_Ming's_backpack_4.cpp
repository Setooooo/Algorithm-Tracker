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
    int n,v;
    cin>>n>>v;
    vector<ull>dp(v+1,0);
    int w,val,s;
    for(int i=0;i<n;++i)
    {
        cin>>w>>val>>s;
        if(s)
        {
            for(int k=1;k<=s;s-=k,k+=k){
                for(int j=v;j>=k*w;--j)
                    dp[j]=max(dp[j],dp[j-w*k]+val*k);
            }
            if(s)
                for(int j=v;j>=w*s;--j)
                    dp[j]=max(dp[j],dp[j-w*s]+val*s);
        }
        else{
            for(int j=w;j<=v;++j)
                dp[j]=max(dp[j],dp[j-w]+val);
        }
    }
    cout<<dp[v];
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