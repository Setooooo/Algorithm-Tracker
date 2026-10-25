// I. 小鸡的排列构造的 checker
// https://ac.nowcoder.com/acm/contest/95338/I
// 练习模板：补全 TODO 后再提交，当前输出 -1 仅用于占位。

#include <iostream>
#include <vector>

using namespace std;

unsigned long long MAXN = 1e5; //题目中最大是1e5

// TODO 1：在这里定义你需要的数据结构和函数。
// 主席树节点结构
struct node {
    int val; // 主席树上统计的值(当前范围内出现数字的个数)
    int cl,cr; //左右孩子
};
struct head {

};
// 我需要一个主席树，来为我维护数组前缀中在[1,c]这个范围内出现的数的个数

// 主席树应该是多大的？
// 应该是两倍的原数组的长度 考虑到这是主席树，实际上还需要 加上每一次更新然后会发生新增的元素 nlogn
// 主席树的下标应该是从哪里开始呢？


void solve() {
    int n, m;
    cin >> n >> m;

    // 使用从 1 开始的下标。
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // TODO 2：初始化本组数据需要的状态，并完成预处理。
    // 如果使用全局变量或节点池，注意多组数据之间的重置。

    for (int i = 0; i < m; ++i) {
        int l, r, c;
        cin >> l >> r >> c;

        // TODO 3：计算原来位于下标 c 的元素排序后的新下标。
        // 每次询问均基于初始排列。
        int answer = -1;
        cout << answer << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) {
        return 0;
    }

    while (T--) {
        solve();
    }

    return 0;
}
