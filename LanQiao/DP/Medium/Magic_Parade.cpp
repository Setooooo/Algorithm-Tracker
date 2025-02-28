//
// Created by beHe on 25-3-1.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;
constexpr int N=1e5+10;
int dp[2][N][3];
int ans[2][3];

void solve()
{
    int n;
    cin>>n;
//    memset(dp,-1,sizeof(dp));
    vector<vector<bitset<3>>>arr(2,vector<bitset<3>>(n+1));
    string str;
    for(int i=1;i<=n;++i)
    {
        cin>>str;
        if(str.find('0')!=string::npos) arr[0][i][0]=true;
        if(str.find('2')!=string::npos) arr[0][i][1]=true;
        if(str.find('4')!=string::npos) arr[0][i][2]=true;
    }
    for(int i=1;i<=n;++i)
    {
        cin>>str;
        if(str.find('0')!=string::npos) arr[1][i][0]=true;
        if(str.find('2')!=string::npos) arr[1][i][1]=true;
        if(str.find('4')!=string::npos) arr[1][i][2]=true;
    }
//    for(int j=0;j<3;++j)
//        dp[1][0][j]=0;
//    set<int>se,re;
    memset(ans,-1,sizeof ans);

    for(int j=0;j<3;++j)
        ans[1][j]=0;
    for(int i=1;i<=n;++i)
    {
//        for(int j=0;j<3;++j)
//            dp[0][i][j]=dp[0][i-1][j],dp[1][i][j]=dp[1][i-1][j];
//        int ma=-1,mb=-1;
//        se.clear(),re.clear();
//        for(int j=0;j<3;++j) {
//            if(arr[0][i][j]) se.insert(j);
//            if(arr[1][i][j]) re.insert(j);
//        }
//        for(auto k:se) ma=max(ma,dp[1][i-1][k]);
//        for(auto k:re) mb=max(mb,dp[0][i-1][k]);
//        for(auto k:se) dp[0][i][k]=max(dp[0][i][k],ma+1);
//        for(auto k:re) dp[1][i][k]=max(dp[1][i][k],mb+1);

        int x=-1,y=-1;
        for(int j=0;j<3;++j)
        {
            if(arr[0][i][j]) x=max(x,ans[1][j]);
            if(arr[1][i][j]) y=max(y,ans[0][j]);
        }
        for(int j=0;j<3;++j)
        {
            if(arr[0][i][j]) ans[0][j] = max(ans[0][j],x+1);
            if(arr[1][i][j]) ans[1][j] = max(y+1,ans[1][j]);
        }
    }
    int res = 0;
    for(int j = 0 ; j < 3 ; j ++) res = max({res,ans[0][j],ans[1][j]});
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file(R"(D:\download\19731.in)");
    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}