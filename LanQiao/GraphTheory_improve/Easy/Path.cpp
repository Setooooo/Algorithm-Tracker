//
// Created by beHe on 25-3-27.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;
constexpr int N=2022;

ll dist[N];
struct node{
    int po;
    ll w;
    bool operator<(const node&ri)const{
        return w>ri.w;
    }
};
bitset<N>vis;

ll lcm(int a,int b){
    return a*b/__gcd(a,b);
}

void solve()
{
    fill(dist,dist+N,2e10);
    priority_queue<node>pq;
    pq.emplace(1,dist[1]=0);
    while(!pq.empty()){
        int now=pq.top().po; pq.pop();
        if(vis[now]) continue; vis[now]=true;
        for(int i=max(1,now-21);i<=min(now+21,2021);++i){
            if(vis[i]) continue;
            int lu=lcm(i,now);
            if(dist[i]>dist[now]+lu) pq.emplace(i,dist[i]=lu+dist[now]);
        }
    }
    cout<<dist[2021];
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