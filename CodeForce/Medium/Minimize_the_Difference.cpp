//
// Created by beHe on 25-3-23.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...
//Minimize the Difference
using namespace std;

using ll=long long;
using ull=unsigned long long;

struct node{
    ll sum,cnt;
public:
    node():sum(0),cnt(0){};
    node(ll x,ll y):sum(x),cnt(y){};
    ll get_avg() const{ return sum/cnt; }
    node operator+(const node&right ){
        return node{sum+right.sum,cnt+right.cnt};
    }
};

void solve()
{
    ll n,x;
    cin>>n;
    cin>>x;
    deque<node>de;
    de.emplace_back(x,1);
    for(int i=1;i<n;++i){
        cin>>x;
        node res(x,1);
        while(!de.empty()){
            auto bac=de.back();
            if(bac.get_avg()>=res.get_avg())  res=bac+res,de.pop_back();
            else break;
        }
        de.emplace_back(res);
    }
    ll pre=de.front().get_avg(),las=(de.back().sum+de.back().cnt-1)/de.back().cnt;
    cout<<las-pre<<'\n';
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