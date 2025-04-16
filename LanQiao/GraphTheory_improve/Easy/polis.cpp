//
// Created by beHe on 25-3-30.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//城邦
using namespace std;

using ll=long long;
using ull=unsigned long long;

class Solution{
    vector<vector<int>>dist;
    vector<vector<char>>number;
public:
    Solution():dist(2022,vector<int>(2022,0)),
    number(2022,vector<char>(4)){
        for(int i=1;i<2022;++i)
            number[i][3]=i/1000,number[i][2]=i/100%10,number[i][1]=i/10%10,number[i][0]=i%10;
        for(int i=1;i<2022;++i){
            dist[i][i]=0;
            for(int j=i+1;j<2022;++j){
                for(int k=0;k<4;++k)
                    if(number[i][k]!=number[j][k]) dist[i][j]+=number[i][k]+number[j][k];
                dist[j][i]=dist[i][j];
            }
        }
    }
    const vector<vector<char>>& renumber(){
        return number;
    }
    const vector<vector<int>>& redist(){
        return dist;
    }
};

class CAL{
    const vector<vector<int>>&dist;
    bitset<2022>vis;
    ll ans,cnt;
    struct node{
        int p;
        ll weight;
        bool operator<(const node&ri) const {return weight>ri.weight;}
    };
public:
    CAL(const vector<vector<int>>&dist_):
    dist(dist_),vis(false),ans(0),cnt(0){
        priority_queue<node>pq;
        pq.push({1,0});
        while(!pq.empty()&&cnt<2021){
            int x=pq.top().p,w=pq.top().weight; pq.pop();
            if(vis[x]) continue; vis[x]=true,++cnt,ans+=w;
            for(int i=1;i<2022;++i){
                if(vis[i]) continue; pq.push({i,dist[i][x]});
            }
        }
        cout<<ans;
    }
};

class CBL{
    const vector<vector<int>>&dist;
    vector<int>fa;
    struct node{
        int u,v,w;
        bool operator<(const node&ri) const{return w>ri.w;}
    };
    int cnt,ans;
public:
    CBL(const vector<vector<int>>&dist_):dist(dist_),fa(2022,0),cnt(0),ans(0){
        for(int i=1;i<2022;++i) fa[i]=i;
        priority_queue<node>pq;
        for(int i=1;i<2022;++i)
            for(int j=i+1;j<2022;++j)
                pq.push({i,j,dist[i][j]});
        while (!pq.empty()&&cnt<2020){
            auto [x,y,w]=pq.top(); pq.pop();
            int fx=get(x),fy=get(y);
            if(fx==fy) continue;
            ++cnt,ans+=w; fa[fx]=fy;
        }
        cout<<ans;
    }
    int get(int x){
        if(fa[x]!=x) return fa[x]=get(fa[x]);
        return x;
    }
};

void solve()
{
    Solution one;
//    CAL two(one.redist());
    CBL three(one.redist());
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