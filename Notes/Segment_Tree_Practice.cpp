// 普通线段树练习：单点加、区间求和。
// 题目和参数约定见同目录的 Segment_Tree_Practice.md。
// 补全 build、query、add；当前 query 的返回值只是占位值。

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> a;
vector<ll> tree;

// p：当前节点编号；[l, r]：当前节点负责的原数组下标范围。
// tree[p] 应当保存当前数组在 [l, r] 内的元素和。
// 根节点编号为 1，左右孩子编号分别为 p * 2 和 p * 2 + 1。

void build(int p, int l, int r) {
    // TODO 1：根据初始数组 a 建树。
}

ll query(int p, int l, int r, int L, int R) {
    // TODO 2：查询当前数组在闭区间 [L, R] 内的元素和。
    return 0; // 占位值，完成实现后替换。
}

void add(int p, int l, int r, int pos, ll delta) {
    // TODO 3：将下标 pos 的元素增加 delta，并维护统计信息。
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    a.assign(n + 1, 0);
    tree.assign(4 * n + 5, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    build(1, 1, n);

    for (int i = 0; i < m; ++i) {
        int op;
        cin >> op;

        if (op == 1) {
            int pos;
            ll delta;
            cin >> pos >> delta;
            add(1, 1, n, pos, delta);
        } else if (op == 2) {
            int L, R;
            cin >> L >> R;
            cout << query(1, 1, n, L, R) << '\n';
        }
    }

    return 0;
}
