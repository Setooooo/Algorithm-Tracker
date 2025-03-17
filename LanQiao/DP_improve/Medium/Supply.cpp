//
// Created by beHe on 25-3-9.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

inline double getDistance(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
constexpr ll N=25,inf=2e8;
double d[N][N];
ll n,D;

double dp[(1<<20)+9][N];

void solve() {
    cin >> n >> D;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    double res;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            res = getDistance(arr[i],arr[j]);
            d[i][j]=res<=D?res:inf;
        }
    for(int k=0;k<n;++k)
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
    for(int sta=2;sta<(1<<n);++sta)
        for(int i=0;i<n;++i)
            dp[sta][i]=inf;
    dp[1][0]=0;
    for(int sta=2;sta<(1<<n);++sta)
        for(int i=0;i<n;++i)
        {
            if(((sta>>i)&1)==0) continue;
            int last_sta=sta^(1<<i);
            for(int j=0;j<n;++j){
                if(((last_sta>>j)&1)==0) continue;
                dp[sta][i]=min(dp[sta][i],dp[last_sta][j]+d[j][i]);
            }
        }
    double ans=inf;
    for(int i=1;i<n;++i)
        ans=min(ans,dp[(1<<n)-1][i]+d[i][0]);
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