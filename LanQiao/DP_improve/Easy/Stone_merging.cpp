//
// Created by beHe on 25-3-7.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
    int n,x;
    cin>>n;
    vector<vector<ull>>dp(n+1,vector<ull>(n+1,0));
    vector<ull>pre(n+1,0);
    for(int i=1;i<=n;++i)
        cin>>x,pre[i]+=pre[i-1]+x;
    ull minn=1e11;
    for(int len=2;len<=n;++len){
        for(int st=1;st<=n-len+1;++st)
        {
            minn=1e11;
            for(int ed=st;ed-st+1<len;ed++)
            {
                minn=min(minn,dp[st][ed]+dp[ed+1][st+len-1]+pre[ed]-pre[st-1]+pre[st+len-1]-pre[ed]);
            }
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