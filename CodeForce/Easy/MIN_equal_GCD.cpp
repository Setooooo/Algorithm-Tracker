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
    vector<ll>arr(n);
    for(auto &i:arr) cin>>i;
    sort(arr.begin(), arr.end());
    ll cnt=1,x=arr[0];
    for(int i=1;i<n;++i) if(arr[i]==x) ++cnt; else break;
    if(cnt>=2) cout<<"Yes\n";
    else{
        int vis=0;
        ll al=0;
        for(int i=1;i<n;++i) {
            if(arr[i]%x==0) ++vis,al=__gcd(al,arr[i]);
        }
        if(vis&&al==x){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
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