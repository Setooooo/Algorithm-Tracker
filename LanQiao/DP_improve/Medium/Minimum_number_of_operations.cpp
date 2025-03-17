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
    string a,b;
    cin>>a>>b;
    int n=a.size();
    a=' '+a;
    b=' '+b;
    vector<vector<int>>dp1(n + 1, vector<int>(n + 1, 1e8));
    for(int i=1;i<=n;++i) dp1[i][i]=1;
    for(int i=1;i<n;++i){
        for(int j=1;j+i<=n;++j)
            if(b[j]==b[j+i]) dp1[j][j+i]=min(dp1[j+1][j+i],dp1[j][j+i-1]);
            else{
                for(int x=0;x<i;++x){
                    dp1[j][j+i]=min(dp1[j][j+i],dp1[j][j+x]+dp1[j+x+1][j+i]);
                }
            }
    }

    vector<int>f(n+1,1e8);
    for(int i=1;i<=n;++i) f[i]=dp1[1][i];
    for(int i=1;i<=n;++i)
    {
        if(a[i]==b[i]) f[i]=min(f[i-1],f[i]);
        for(int j=1;j<i;++j) f[i]=min(f[i],f[j]+dp1[j+1][i]);
    }
    cout<<f[n];
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