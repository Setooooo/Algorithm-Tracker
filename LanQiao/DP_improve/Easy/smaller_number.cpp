//
// Created by beHe on 25-3-11.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

void solve()
{
    string str; cin>>str;
    int n=str.size();
    ll ans=0;
    vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
    for(int i=1;i<n;++i)
        for(int j=0;j+i<n;++j)
        {
            dp[j][j+i]=str[j+i]==str[j]?dp[j+1][i+j-1]:str[j]>str[j+i];
            if(dp[j][j+i]) ++ans;
        }
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