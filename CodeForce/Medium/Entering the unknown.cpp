//
// Created by Seto on 2026-09-16
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

ull getNumber(ull number) {
    string s = std::to_string(number);
    ull c= 0;
    for (const auto i:s) {
        if (i>c) {
            c = i;
        }
    }
    return c-'0';
}

void solve()
{
    // 读取数据
    int n;
    cin>>n;
    vector<ull> numbers(n);
    for (auto &x:numbers) cin>>x;
    // 计算前缀和（mod 情况下 1~9）
    vector<vector<ull>>preArr(9,vector<ull>(n+1,0));
    for (int i=1;i<=9;++i) {
        auto &arr = preArr[i-1];
        for (int j=1;j<=n;++j) {
            arr[j] = (arr[j-1] + numbers[j-1])%i;
        }
    }
    // 统计每组前缀和  的答案数量
    ull ans = 0;
    // for (int i=0;i<n;++i) {
    //     ans+= numbers[i]%getNumber(numbers[i])==0;
    // }
    for (int d=1;d<=9;++d) {
        // 遍历每个d模数组
        // 遍历每个原始数据的数字 x
        // x 当前最大 digital < d 放入 cnt桶中，将cnt s 添加到ans 中表示原来左边是开头，或者是一个等于d的digital，同时加入couldUse vector 表示可以被使用的前缀和
        // x digital == d 表示现在可以使用 原来的前缀和数组，来计算满足地数组
        // x digital > d 表示现在不能再去使用原来的数组了，以及统计可能的种类了，所以全部丢弃
        vector<ull>couldUse{0};
        auto &arr = preArr[d-1];
        vector<ull>cnt(d+1,0);
        for (int j=1;j<=n;++j) {
            auto x = getNumber(numbers[j-1]);
            auto &y = arr[j];
            if (x<d) {
                ans+=cnt[y];
                couldUse.emplace_back(y);
            } else if (x>d) {
                couldUse.clear();
                couldUse.emplace_back(y);
                std::fill(cnt.begin(),cnt.end(),0);
            }else {
                for (auto &e:couldUse) cnt[e]++;
                couldUse.clear();
                ans+=cnt[y];
                couldUse.emplace_back(y);
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    // ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    // cin.rdbuf(file.rdbuf());

    int T=1;
    cin>>T;
    while (T--)
    {
        solve();
    }
}