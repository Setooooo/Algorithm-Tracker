//
// Created by beHe on 25-3-8.
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
    vector<int>arr(n+1,0);
    vector<vector<int>>dp(n+1,vector<int>(n+1));

    for(int i=1;i<=n;++i)
        cin>>arr[i],dp[i][i]=dp[i][i-1]=1;

    int minn=1e5;

    for(int len=2;len<=n;++len){
        for(int st=1;st<=n-len+1;++st){
            minn=1e5;
            if(arr[st]==arr[st+len-1]) minn=dp[st+1][st+len-2];
            for(int ed=st;ed-st+1<len;++ed)
                minn=min(minn,dp[st][ed]+dp[ed+1][st+len-1]);
            dp[st][st+len-1]=minn;
        }
    }

    cout<<dp[1][n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}