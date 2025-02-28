//
// Created by beHe on 25-3-1.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

int arr[110][110];

void solve()
{
    int n,x;
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            cin>>arr[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j){
            if(j==1)
                arr[i][j]+=arr[i-1][j];
            else if(j==i)
                arr[i][j]+=arr[i-1][j-1];
            else
                arr[i][j]+=max(arr[i-1][j],arr[i-1][j-1]);
        }
    int ans=0;
    for(int i=1;i<=n;++i)
        ans=max(ans,arr[n][i]);
    cout<<ans;
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