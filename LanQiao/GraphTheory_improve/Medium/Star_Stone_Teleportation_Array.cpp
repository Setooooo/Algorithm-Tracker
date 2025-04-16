//
// Created by beHe on 25-3-24.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

constexpr int INF = 0x3f3f3f3f;
int n, a, b, cnt = 0;

struct Edge{
    int po,w;
public:
    Edge(int x,int y):po(x),w(y){};
    bool operator<(const Edge&right) const{
        return w>right.w;
    }
};

constexpr int N= 1e5+10;
vector<vector<Edge>>graph(N*2);
bitset<N*2>vis;
priority_queue<Edge>pq;
vector<int>prime;
ll dis[N*2];

inline void add(int x,int y,int w){
    graph[x].push_back({y,w});
}
void get_prime(){
    int ed=10000;
    vector<int>res(ed+1,0);
    for(ll i=2;i<=ed;++i) {
        if(!res[i]) prime.emplace_back(i);
        for(const auto &j:prime) {
            if(j>i||j>ed/i) break;
            res[j*i]=j;
            if(i%j) break;
        }
    }
//    for(const auto &i:prime) cout<<i<<' ';
}

ll get_div(ll x){
    static ll li=prime.size();
    ll res=0,p=0;
    while(x/prime[p]>=prime[p]&&p<li) {
        if(x%prime[p]==0)
            res+=prime[p],x/=prime[p];
        else ++p;
    }
    if(x>1) res+=x;
    return res;
}

void dijkstra(int point){
    memset(dis,INF,sizeof(dis));
    pq.push({point,(int)(dis[point]=0)});
    while(!pq.empty()){
        int x=pq.top().po; pq.pop();
        if(vis[x]) continue; vis[x]=true;
        for(const auto &[y,w]:graph[x])
            if(dis[y]>w+dis[x]) pq.push({y,(int)(dis[y]=dis[x]+w)});
    }
}

void solve()
{
    get_prime();
    cin>>n>>a>>b;
    int x;
    ll f;
    for(int i=1;i<=n;++i){
        cin>>x;
        f=get_div(x);
        f=(f%n)+1;
        add(f,i,1),add(i,f,1);
        add(n+f+1,i,0),add(i,n+f+1,1);
    }
    dijkstra(a);
    if(dis[b]==INF) cout<<-1;
    else cout<<dis[b];
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