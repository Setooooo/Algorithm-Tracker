// CF438D - The Child and Sequence
// https://codeforces.com/problemset/problem/438/D
//
// 区间取模线段树：维护区间和 sum 与区间最大值 mx。
// 输入没有测试组数 T，数组下标从 1 开始，所有区间都是闭区间。
// 1 l r   ：查询 a[l] + ... + a[r]。
// 2 l r x ：将区间内每个元素分别对 x 取模。
// 3 k x   ：把 a[k] 赋值为 x。
// 1 <= n, m <= 100000；初始值与操作参数 x 均在 [1, 1000000000]。
//
// 当 mx < x 时，整段取模不会改变元素，可以跳过。
// 每次有效取模至少使元素减半，累计有效修改次数有界。

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct Node {
    ll sum = 0; // 当前区间的元素和，可能超过 int 范围。
    int mx = 0; // 当前区间的最大值；取模后元素可能为 0。
};

vector<int> a;     // 建树用的初始数组；后续修改由线段树维护。
vector<Node> Seg;

// index：当前树节点编号；[L, R]：它负责的原数组下标范围。
// 根节点为 1，左右孩子为 index * 2、index * 2 + 1。
// [l, r]：本次操作的目标区间，与当前节点负责的 [L, R] 区分。

void pushUp(int index) {
    // 根据左右孩子，更新当前节点的 sum 和 mx。
    int cl = index*2;
    int cr = index*2+1;
    Seg[index].sum = Seg[cl].sum + Seg[cr].sum;
    Seg[index].mx = max(Seg[cl].mx, Seg[cr].mx);
}

void build(int index, int L, int R) {
    // 根据初始数组 a 建树。
    // 叶子的两个统计值应与初始元素一致；非叶子维护孩子和父节点。
    if (L==R) {
        Seg[index].sum = a[L];
        Seg[index].mx = a[L];
    }else {
        int cl = index*2;
        int cr = index*2+1;
        int mid = (L+R)/2;
        build(cl, L, mid);
        build(cr, mid+1, R);
        pushUp(index);
    }
}

ll query(int index, int L, int R, int l, int r) {
    // 返回当前数组在 [l, r] 内的元素和。
    // 处理完全覆盖和部分相交，合并时使用 long long。
    if (l<=L&&R<=r) {
        return Seg[index].sum;
    }
    int cl = index*2;
    int cr = index*2+1;
    int mid = (L+R)/2;
    ll sum = 0;
    if (l<=mid) sum += query(cl, L, mid, l, r);
    if (r>mid) sum += query(cr, mid+1, R, l, r);
    return sum;
}

void pointSet(int index, int L, int R, int pos, int value) {
    // 把 a[pos] 赋值为 value；注意这是赋值，不是增加。
    // 正确修改叶子，并在回溯时维护父节点的两个统计值。
    if (L==R) {
        Seg[index].sum = value;
        Seg[index].mx = value;
    }else {
        int cl = index*2;
        int cr = index*2+1;
        int mid = (L+R)/2;
        if (pos<=mid) pointSet(cl, L, mid, pos, value);
        if (pos>mid) pointSet(cr, mid+1, R, pos, value);
        pushUp(index);
    }
}

void rangeMod(int index, int L, int R, int l, int r, int x) {
    // 将当前数组在 [l, r] 内的元素分别对 x 取模。
    // 通过最大值剪枝，必要时递归到叶子修改，再回溯维护统计值。
    // 注意边界：mx == x、x == 1、元素已经为 0、目标区间只有一个点。
    // 单点赋值后，该元素最多重新增加 O(log A) 次有效取模，A <= 1e9。
    if (L==R) {
        Seg[index].sum%=x;
        Seg[index].mx=Seg[index].sum;
        return;
    }
    int cl = index*2;
    int cr = index*2+1;
    int mid = (L+R)/2;
    if (l<=L&&R<=r) {
        if (Seg[index].mx<x) return;
        rangeMod(cl, L, mid, l, r, x);
        rangeMod(cr, mid + 1, R, l, r, x);
    }else {
        if (l<=mid) rangeMod(cl, L, mid, l, r, x);
        if (r>mid) rangeMod(cr, mid + 1, R, l, r, x);
    }
    pushUp(index);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    a.assign(n + 1, 0);
    Seg.assign(4 * n + 5, Node{});

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);

    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        } else if (type == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            rangeMod(1, 1, n, l, r, x);
        } else if (type == 3) {
            int pos, value;
            cin >> pos >> value;
            pointSet(1, 1, n, pos, value);
        }
    }

    return 0;
}

/*
官方样例 1
输入：
5 5
1 2 3 4 5
2 3 5 4
3 3 5
1 2 5
2 1 3 3
1 1 3

期望输出：
8
5

自拟边界样例
检查：大整数区间和、mx == x、取模后为 0、重新赋值、
单点区间、mx < x 时跳过、x == 1。
输入：
3 10
1000000000 1000000000 1000000000
1 1 3
2 1 3 1000000000
1 1 3
3 2 9
2 2 2 4
1 2 2
2 1 3 2
1 1 3
2 1 3 1
1 1 3

期望输出：
3000000000
0
1
1
0
*/
