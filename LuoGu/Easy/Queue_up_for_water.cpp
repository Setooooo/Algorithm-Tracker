//
// Created by beHe on 25-3-8.
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

vector<ll>a(1000),b(1000);// a 数组保存等待时间 b 数组保存序号

// 这个排序是对 b 数组保存的序号排序，排序的规则是将序号对应a数组中的值较小的序号排在前面
// 也就是a[b[0]]是最小，a[b[1]]是次小
bool cmp(int left,int right){
    return a[left]<a[right];
}

void solve()
{
    int n;
    cin>>n;
    ll sum=0,pre=0;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) b[i]=i;

    sort(b.begin(),b.begin()+n,cmp);

    for(int i=0;i<n-1;++i)
        pre+=a[b[i]],sum+=pre;
    //这里从让序号对应的值较小的先接水

    for(int i=0;i<n;++i) cout<<b[i]+1<<' ';

    cout<<'\n';
    cout<<fixed<<setprecision(2)<<sum*1.0/n;
    // 黄色酸奶好喝 这个颜色和我的配色好像是一样的欸
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

//    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
//    cin.rdbuf(file.rdbuf());

    int T=1;
    while (T--)
    {
        solve();
    }
}