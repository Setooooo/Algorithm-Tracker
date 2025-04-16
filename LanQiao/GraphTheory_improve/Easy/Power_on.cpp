//
// Created by beHe on 25-3-30.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//通电
using namespace std;

using ll=long long;
using ull=unsigned long long;

class Pre{
    int n;
    struct node{
        int id,x,y,h;
    };
    vector<node>cust;
    vector<vector<double>>dist;
public:
    Pre(int n_):n(n_),cust(n),dist(n,vector<double>(n,0)){
        for(int i=0;i<n;++i) cin>>cust[i].x>>cust[i].y>>cust[i].h,cust[i].id=i;
        for(int i=0;i<n;++i){
            dist[i][i]=0;
            for(int j=i+1;j<n;++j) dist[i][j]=dist[j][i]=cal(cust[i],cust[j]);
        }
    }
    double cal(const node&le,const node&ri)const {
        return sqrt((le.x-ri.x)*(le.x-ri.x)+(le.y-ri.y)*(le.y-ri.y))+(le.h-ri.h)*(le.h-ri.h);
    }
    const vector<vector<double>>&get_dist(){return dist;}
};

class Solution{
    const vector<vector<double>>&dist;
    int n,cnt;
    double ans;
    struct node{
        int p;double weight;
        bool operator<(const node&ri) const{return weight>ri.weight;}
    };
    bitset<1010>vis;
public:
    Solution(const vector<vector<double>>&dist_):dist(dist_),n(dist_.size()),cnt(0),ans(0),vis(false){
        priority_queue<node>pq;
        pq.push({0,0});
        while(!pq.empty()&&cnt<n){
            auto [x,w]=pq.top(); pq.pop();
            if(vis[x]) continue; vis[x]=true,cnt++,ans+= w;
            for(int i=0;i<n;++i){
                if(vis[i]) continue; pq.push({i,dist[x][i]});
            }
        }
        cout<<fixed<<setprecision(2)<<ans;
    }
};


void solve()
{
    int n;
    cin>>n;
    Pre one(n);
    Solution two(one.get_dist());
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