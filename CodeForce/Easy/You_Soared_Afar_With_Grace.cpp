//
// Created by beHe on 25-4-12.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

vector<pair<int,int>>ans;

inline void work(int x,int y,vector<int>&a,vector<int>&b,vector<int>&vis){
    if(x==y) return;
    ans.emplace_back(x,y);
    swap(a[x],a[y]);
    swap(vis[a[x]],vis[a[y]]);
    swap(b[x],b[y]);
}

void solve()
{
    int n;
    cin>>n;
    int cnt_equal=0,idx_qual=-1,flag=1;
    vector<int> a(n),b(n),vis(n+1,-1);
    for(int i=0;i<n;++i) cin>>a[i],vis[a[i]]=i;
    for(auto &i:b) cin>>i;
    for(int i=0;i<n;++i){
        if(a[i]==b[i]){
            if((n&1)==0||cnt_equal){
                    cout<<"-1\n";
                    return;
            }
            cnt_equal++,idx_qual=i;
        }else{
            if(b[vis[b[i]]]!=a[i]){
                cout<<"-1\n";
                return;
            }

        }
    }
    if(n&1) work(idx_qual,n/2,a,b,vis);
    for(int i=0;i<n/2;++i) work(vis[b[i]],n-i-1,a,b,vis);
    cout<<ans.size()<<'\n';
    for(auto &[x,y]:ans){
        cout<<x+1<<' '<<y+1<<'\n';
    }
    ans.clear();
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