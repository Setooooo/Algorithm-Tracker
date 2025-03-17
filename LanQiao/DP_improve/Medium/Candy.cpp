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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>arr(n+1,0);
    vector<int>dp((1<<m)+1,1e8);
    int x;
    for(int i=0;i<n;++i){
        for(int j=0;j<k;++j)
        {
            cin>>x;
            arr[i]|=1<<(x-1);
        }
    }
    dp[0]=0;
    for(int sta=0;sta<(1<<m);++sta){
        for(int i=0;i<n;++i){
            dp[sta|arr[i]]=min(dp[sta]+1,dp[sta|arr[i]]);
        }
    }
    int ans=dp[(1<<m)-1];
    if(ans==1e8)
        cout<<"-1";
    else
        cout<<ans;
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