//
// Created by beHe on 25-4-6.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;



void solve()
{
    int n,x,k;
    cin>>n>>x>>k;
    vector<ll>b(n),c(n),dp(k+1,0),cost(n);
    for(auto &i:b) cin>>i;
    for(auto &i:c) cin>>i;
    cost[0]=0;
    vector<int>wei;
    for(int i=0;i<n;++i){
        if(x==1) {
            cost[i]=b[i];
            continue;
        }
        auto j=b[i];
        while(j){
            wei.emplace_back(j%x);
            j/=x;
        }
        ll res=0;
        res=wei.size()-1;
        for(const auto s:wei) res+=s;
        cost[i]=res;
        wei.clear();
    }
    for(int i=0;i<n;++i){
        for(int j=k;j>=cost[i];--j)
            dp[j]=max(dp[j],dp[j-cost[i]]+c[i]);
    }
    cout<<dp[k];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
//    cin>>T;
    while (T--)
    {
        solve();
    }
}