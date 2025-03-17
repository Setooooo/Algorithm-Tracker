//
// Created by beHe on 25-3-9.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
    string a;
    cin>>a;
    int n=a.size();
    a=' '+a;
    vector<vector<int>>dp(n+1,vector<int>(n+1,1e8));
    for(int i=1;i<=n;++i) dp[i][i]=1;
    for(int len=2;len<=n;++len){
        for(int st=1;st+len-1<=n;++st){
            if(a[st]==a[st+len-1]) dp[st][st+len-1]=min(dp[st+1][st+len-1],dp[st][st+len-2]);
            else{
                for(int ed=st;ed-st+1<len;++ed)
                    dp[st][st+len-1]=min(dp[st][st+len-1],dp[st][ed]+dp[ed+1][st+len-1]);
            }
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