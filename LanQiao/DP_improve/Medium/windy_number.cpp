//
// Created by beHe on 25-3-15.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

int a[12];
ll dp[12][2][2][10];

ll dfs(int pos,bool limit,bool st,bool is,int pre)
{
    if(pos<0) return (int)is;
    if(!limit&&dp[pos][st][is][pre]!=-1) return  dp[pos][st][is][pre];
    ll res=0;int up=limit?a[pos]:9;
    for(int i=0;i<=up;++i)
        res+=dfs(pos-1,limit && (i==up),st||(i>0),is&&(!st||abs(i-pre)>=2),i);
    if(!limit) dp[pos][st][is][pre]=res;
    return res;
}

ll h(ll n)
{
    int pos=0;
    while (n) a[pos++]=n%10,n/=10;
    return dfs(pos-1,true,false,true,10);
}


void solve()
{
    ll x,y;
    cin>>x>>y;
    cout<<h(y)-h(x-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());
    memset(dp,-1,sizeof(dp));
    int T=1;
    while (T--)
    {
        solve();
    }
}