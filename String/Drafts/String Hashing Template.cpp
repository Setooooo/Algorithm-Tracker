//
// Created by Seto on 2026-02-05
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct HashPair {
    ll h1, h2; // 改为 ll，方便处理负数逻辑
    bool operator==(const HashPair& x) const {
        return h1 == x.h1 && h2 == x.h2;
    }
};

class StringHash {
private:
    // 模数和基数
    static const ll MOD1 = 1e9 + 7;
    static const ll MOD2 = 1e9 + 9;
    static const ll BASE1 = 131;
    static const ll BASE2 = 13331;

    // 存储数组改为 ll
    vector<ll> h1, h2;
    vector<ll> p1, p2;

public:
    StringHash(const string& s) {
        int n = s.size();
        // 初始化大小
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        p1.assign(n + 1, 0);
        p2.assign(n + 1, 0);

        // [重要] 幂次数组第0位必须是 1
        p1[0] = 1;
        p2[0] = 1;

        for (int i = 0; i < n; ++i) {
            // [修复] h2 加上 s[i]
            // 注意：s[i] 最好强转为 ll 避免溢出警告，虽通常没事
            h1[i + 1] = (h1[i] * BASE1 + s[i]) % MOD1;
            p1[i + 1] = (p1[i] * BASE1) % MOD1;

            h2[i + 1] = (h2[i] * BASE2 + s[i]) % MOD2;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
        }
    }

    HashPair query(int l, int r) {
        // [修复] 减法处理
        // 公式：(hash[r] - hash[l] * P[len]) % MOD
        // 结果可能是负数，所以先 % MOD，再 + MOD，再 % MOD
        // 或者直接 (A - B % MOD + MOD) % MOD

        ll res1 = (h1[r + 1] - h1[l] * p1[r - l + 1]) % MOD1;
        if (res1 < 0) res1 += MOD1; // 因为是 long long，这里可以正常判断负数

        ll res2 = (h2[r + 1] - h2[l] * p2[r - l + 1]) % MOD2;
        if (res2 < 0) res2 += MOD2;

        return HashPair{res1, res2};
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);



    int T=1;
//    cin>>T;
    while (T--)
    {
        string str_p,str_s;
        cin>>str_p>>str_s;
        cout<<sol.match_S().size()<<endl;
    }
}