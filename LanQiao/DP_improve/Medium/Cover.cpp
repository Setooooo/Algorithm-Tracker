//
// Created by beHe on 25-3-17.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//覆盖

using namespace std;

using ll=long long;
using ull=unsigned long long;

bool use[1<<8];
ll dp[9][1<<8];

void solve()
{
    int x,cnt;
    for(int sta=0;sta<1<<8;++sta){
        cnt=0; use[sta]=true;
        for(int i=0;i<8;++i){
            if((sta>>i&1)==0) ++cnt;
            else if(cnt&1) {
                use[sta]= false; break;
            }
        }
        if((cnt&1)) use[sta]=false;
    }
    dp[0][0]=1;
    for(int i=1;i<=8;++i)
        for(int sta=0;sta<1<<8;++sta)
            for(int now=0;now<1<<8;++now)
                if((sta&now)==0&&use[now|sta])
                    dp[i][now]+=dp[i-1][sta];
    cout<<dp[8][0];
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