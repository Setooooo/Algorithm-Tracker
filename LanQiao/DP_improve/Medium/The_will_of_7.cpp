//
// Created by beHe on 25-3-16.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

ll dp[20][2][7][7];
int a[20];

ll dfs(int pos,bool limit,bool st,int num,int sum){
    if(pos<0) return (int)((num==0)&&(sum==0));

    if(!limit&&dp[pos][st][num][sum]!=-1) return dp[pos][st][num][sum];
    ll res=0; int up=limit?a[pos]:9;
    for(int i=0;i<=up;++i)
        res+=dfs(pos-1,limit&&(i==up),st||(i>0),(num*10+i)%7,(sum+i)%7);
    if(!limit) dp[pos][st][num][sum]=res;
    return res;
}

ll h(ll n){
    int pos=0;
    while (n) a[pos++]=n%10,n/=10;
    return dfs(pos-1,true,false,0,0);
}

void solve()
{
    ll x,y;
    while (cin>>x>>y){
        if(! x&&!y) break;
        cout<<h(y)-h(x-1)<<'\n';
    }
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