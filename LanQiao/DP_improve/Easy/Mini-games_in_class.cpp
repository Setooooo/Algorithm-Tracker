//
// Created by beHe on 25-3-16.
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
    vector<vector<pair<ll,ll>>>dp(n*2+1,vector<pair<ll,ll>>(n*2+1,{0,0}));
    for(int i=1;i<=n;++i) cin>>dp[i][i].first,dp[i][i].second=0,dp[i+n][i+n]=dp[i][i];

    for(int i=1;i<n;++i){
        for(int st=1;st+i<=n*2;++st){
            pair<ll,ll>res={0,-1};
            for(int k=0;k<i;++k){
                ll sec= dp[st][st+k].first*dp[st+k+1][st+i].first/10+dp[st][st+k].second+dp[st+k+1][st+i].second,
                now=(dp[st][st+k].first*dp[st+k+1][st+i].first)%10;
                if(sec>res.second) res.first=now,res.second=sec;
            }
            dp[st][st+i]=res;
        }
    }
    ll mann=0;
    for(int i=1;i<=n;++i)
        mann=max(mann,dp[i][i+n-1].second);
    cout<<mann;
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