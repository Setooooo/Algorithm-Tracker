//
// Created by beHe on 25-3-2.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
    array<ull,2>dp{};
    ull n,x,res1,res2;
    cin>>n>>x;
    vector<int>arr(n+1,0);
    cin>>arr[1];
    for(int i=2;i<=n;++i){
        cin>>arr[i];
        res1=max({dp[0]+(arr[i-1]^arr[i]),dp[1]+((arr[i-1]+x)^arr[i])});
        res2=max({dp[0]+(arr[i-1]^(arr[i]+x)),dp[1]+((arr[i-1]+x)^(arr[i]+x))});
        dp[0]=res1;dp[1]=res2;
    }
    cout<<max(dp[0],dp[1]);

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}