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
    int n;
    cin>>n;
    vector<pair<int,int>>arr(n);
    string x;
    for(int i=0;i<n;++i){
        cin>>x;
        arr[i].second=x.back()-'0';
        arr[i].first=x.front()-'0';
    }
    vector<int>dp(10,0);
    for(int i=0;i<n;++i)
    {
        dp[arr[i].second]=max(dp[arr[i].second],dp[arr[i].first]+1);
    }
    auto minn= max_element(dp.begin(), dp.end());
    cout<<n-*minn;
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