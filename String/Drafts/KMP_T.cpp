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
        for (int i = 0, j = 0; i < n; i++) {
            // 如果字符不匹配，j 根据 next 数组回退
            // 只要 j > 0 且当前字符不匹配，就一直回退
            while (j > 0 && str_S[i] != str_P[j]) {
                j = next[j - 1];
            }

            // 如果字符匹配，j 前进
            if (str_S[i] == str_P[j]) {
                j++;
            }

            // 如果 j 达到了模式串的长度，说明完全匹配
            if (j == m) {
                res.emplace_back(i - m + 1); // 记录匹配的起始位置
                j = next[j - 1];          // 继续寻找下一个匹配，回退到最大公共前后缀位置
            }
        }
        return res;
    }

    // 辅助函数：打印 next 数组（用于调试）
    void print_next() {
        cout << "Next Array: ";
        for (int x : next) cout << x << " ";
        cout << endl;
    }

private:
    const string str_P;
    const string str_S;
    vector<int> next;

    // 计算 next 数组 (前缀表)
    void count_next() {
        int m = str_P.size();
        next[0] = 0; // 第一个字符的最长相等前后缀长度通常为 0

        // i 是后缀末尾，j 是前缀末尾（同时也是当前最长相等前后缀的长度）
        for (int i = 1, j = 0; i < m; i++) {
            // 前后缀不匹配时，j 回退
            while (j > 0 && str_P[i] != str_P[j]) {
                j = next[j - 1];
            }

            // 匹配时，j 增加
            if (str_P[i] == str_P[j]) {
                j++;
            }

            // 更新 next 数组
            next[i] = j;
        }
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ifstream file(R"(D:\Project\Personal_Projects\GetIt\TEST\test1.txt)");
    cin.rdbuf(file.rdbuf());

    int T=1;
//    cin>>T;
    while (T--)
    {
        solve();
    }
}