//
// Created by beHe on 25-4-5.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//蓝泽的秘密邮件
using namespace std;

using ll=long long;
using ull=unsigned long long;


void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<vector<int>>dp(n+1,vector<int>(3,0));
    for(auto &i:arr) cin>>i;
    for(int i=0;i<n;++i){
        dp[i+1][0]=max(dp[i+1][0],dp[i][0]+((i&1)==0?arr[i]:0));
        if(i+2<=n)
            dp[i+2][1]=max(dp[i+2][1],max(dp[i][0],dp[i][1])+(i&1?arr[i]:arr[i+1]));
        dp[i + 1][2] = max(dp[i + 1][2], max({dp[i][0], dp[i][1], dp[i][2]}) + (i & 1 ? 0 : arr[i]));
    }
    cout<<max({dp[n][0],dp[n][2],dp[n][1]});
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
//    cin>>T;
    while (T--)
    {
        solve();
    }
}