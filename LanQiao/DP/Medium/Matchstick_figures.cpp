//
// Created by beHe on 25-3-1.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

pair<int,int> cost[10]=
        {{6,0},{2,1},{5,2},{5,3},{4,4},{5,5},{6,6},{3,7},{7,8},{6,9}};

void solve()
{
    sort(cost,cost+10,[](const pair<int,int> a,const pair<int,int> b){
        if(a.first==b.first)
            return a.second>b.second;
        return a.first<b.first;
    });
    int s=300,p=0;
    map<int,int>res;
    while (s-cost[p].first>=0){
        ++res[cost[p].second];
        s-=cost[p].first;
        if(res[cost[p].second]==10)
            ++p;
    }
    string ans;
    for(const auto [val,key]:res)
        ans+=string(key,val+'0');
    reverse(ans.begin(), ans.end());
    cout<<ans;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

//    ifstream file("");
//    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}