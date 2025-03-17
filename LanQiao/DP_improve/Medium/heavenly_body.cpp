//
// Created by beHe on 25-3-11.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

struct Info{
    ll x,y,z,w;
};

double cal(Info &a,Info &b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z))*b.w;
}

void solve()
{
    int n;
    cin>>n;
    vector<vector<double>>dp(1<<n,vector<double>(n,1e8)),graph(n,vector<double>(n));
    vector<Info>arr(n);
    for(auto &i:arr)
        cin>>i.x>>i.y>>i.z>>i.w;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            graph[i][j]=cal(arr[i],arr[j]);
    for(int i=0;i<n;++i)
        dp[1<<i][i]=0;
    for(int sta=1;sta<(1<<n);++sta)
    {
        for(int i=0;i<n;++i) {
            if ((sta >> i & 1) == 0) continue;
            int last_sta=sta^(1<<i);
            for(int j=0;j<n;++j){
                if((last_sta>>j&1)==0) continue;
                dp[sta][i]=min(dp[sta][i],dp[last_sta][j]+graph[j][i]);
            }
        }
    }
    double ans=1e8;
    for(int i=0;i<n;++i)
        ans=min(ans,dp[(1<<n)-1][i]);
    cout<<fixed<<setprecision(2)<<ans;
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