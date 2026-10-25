//
// Created by Seto on 2026-02-05
//
#include <bits/stdc++.h>
//There used to be a lot of header files here...

using namespace std;

using ll=long long;
using ull=unsigned long long;

// str_P 模式串 (Pattern), str_S 文本串 (String/Text)
class KMP_TEMPLATE {
public:
    // 构造函数：传入模式串和文本串
    // 注意：去掉了参数中的 const，以便 std::move 能真正生效（移动而非拷贝）
    KMP_TEMPLATE(string _str_P, string _str_S)
        : str_P(std::move(_str_P)), str_S(std::move(_str_S)), next(str_P.size(), 0) {

        // 在构造对象时，立即计算 next 数组
        if (!str_P.empty()) {
            count_next();
        }
    }

    // 将匹配函数设为 public，以便外部调用
    // 返回所有匹配成功的起始下标 (0-based)
    vector<int> match_S() {
        vector<int> res;
        if (str_P.empty()) return res;

        int n = str_S.size();
        int m = str_P.size();

        // i 指向文本串，j 指向模式串
        for (int i=0,j=0;i<n;++i) {
            while (j>0&&str_P[i]==str_S[j]) j = next[j-1];
            if (str_P[i]==str_S[j]) ++j;
            if (j==m) res.emplace_back(i-m+1),j = next[j-1];
        }
        return res;
    }

    // 辅助函数：打印 next 数组（用于调试）
    void print_next() {
        cout << "Next Array: ";
        for (int x : next) cout << x << " ";
        cout << endl;
    }


    const string str_P;
    const string str_S;
    vector<int> next;

    // 计算 next 数组 (前缀表)
    void count_next() {
        int m = str_P.size();
        next[0] = 0; // 第一个字符的最长相等前后缀长度通常为 0

        for (int i = 1,j=0; i < m; i++) {
            while (j > 0&&str_P[i]!=str_P[j]) j=next[j-1];
            if (str_P[i]==str_P[j]) j++;
            next[i] = j;
        }
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    string a,b;
    cin>>a>>b;
    KMP_TEMPLATE sol(b,a);
    vector<int> res = sol.match_S();
    for(auto i:res){
        cout<<i+1<<'\n';
    }
    for(auto j:sol.next){
        cout<<j<<' ';
    }

}