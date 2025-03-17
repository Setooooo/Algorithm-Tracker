//
// Created by beHe on 25-3-13.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr int N=6;

ll dp[N][1<<(N+2)][1<<N];
vector<int>row;

void solve()
{
    int n,m,t=0;
    cin>>n>>m;
    for(int i=0;i<(1<<m);++i)
        if((i&(i<<1)&(i<<2))==0) row.emplace_back(i),++t;
    dp[0][0][0]=1;
    for(int i=1;i<=n+2;++i)
        for(int j=0;j<t;++j)
            for(int k=0;k<t;++k)
                for(int e=0;e<t;++e)
                    if(!(row[j]&row[k]&row[e])) dp[i][j][k]+=dp[i-1][k][e];
    cout<<dp[n+2][0][0];
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