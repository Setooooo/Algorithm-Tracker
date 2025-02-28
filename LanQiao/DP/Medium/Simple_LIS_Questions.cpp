//
// Created by beHe on 25-2-28.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

using vit=vector<int>::iterator;

vector<int>::iterator MyBindSearch(vit st,vit ed,const int val){
    int count= distance(st,ed),step;
    auto it=ed;
    while (count>0){
        it=st;
        step=count/2;
        advance(it,step);
        if(*it>val){
            st=++it;
            count-=step+1;
        }else{
            count=step;
        }
    }
    return st;
}

void solve()
{
    int n;
    cin>>n;
    vector<int>pre(n,1),arr(n),las(n,1),res;
    for(auto &i:arr)
        cin>>i;
    for(int i=0;i<n;++i){
        auto it= lower_bound(res.begin(), res.end(),arr[i]);
        if(it!=res.end()){
            pre[i]=it-res.begin()+1;
            *it=arr[i];
        }else{
            res.emplace_back(arr[i]);
            pre[i]=res.size();
        }
    }
    res.clear();
    for(int i=n-1;i>=0;--i){
        auto it = MyBindSearch(res.begin(),res.end(),arr[i]);
        if(it!=res.end()){
            las[i]=it-res.begin()+1;
            *it=arr[i];
        }else{
            res.emplace_back(arr[i]);
            las[i]=res.size();
        }
    }
    int ans=1;
    for(int i=0;i<n;++i)
    {
        for(int j=i+2;j<n;++j){
            if(arr[i]+1==arr[j]) ans=max(ans,pre[i]+las[j]);
            else if(arr[i]+1<arr[j]) ans=max(ans,pre[i]+las[j]+1);
        }
        if(i<n-1) ans=max(ans,pre[i]+1);
        if(i>0&&arr[i]>0) ans=max(ans,las[i]+1);
    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());


    int T=1;
    while (T--)
    {
        solve();
    }
}