//
// Created by beHe on 25-3-29.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//小朋友崇拜圈
using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
    int n;
    vector<int>wor,time;
    int tim,ans;
public:
    Solution(int n_):n(n_),wor(n+1),time(n+1,0),tim(0),ans(0){
        for(int i=1;i<=n;++i) cin>>wor[i];
        for(int i=1;i<=n;++i){
            if(time[i]) continue;
            time[i]=++tim;
            int p=i,st=tim;
            while(!time[wor[p]]){
                time[wor[p]]=++tim;
                p=wor[p];
            }
            if(time[wor[p]]>=st)
                ans=max(ans,tim-time[wor[p]]+1);
        }
        cout<<ans;
    };
};


void solve()
{
    int n;
    cin>>n;
    Solution one(n);
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