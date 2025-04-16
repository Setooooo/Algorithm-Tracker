//
// Created by beHe on 25-4-11.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;



void solve()
{
    int n;
    cin>>n;
    if((n&1)==0) cout<<-1<<'\n';
    else{
        cout<<n<<' ';
        for(int i=1;i<n;++i) cout<<i<<" \n"[i==n-1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
    cin>>T;
    while (T--)
    {
        solve();
    }
}