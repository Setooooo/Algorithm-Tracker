
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 1e5;
const int INF = 0x7fffffff;

class FHQ_Treap {
    struct node {
        int val, siz, priority, count;
        bool rev;
        node *sl, *sr;

        node() : val(0), siz(1), priority(rand()), count(1), rev(false), sl(nullptr), sr(nullptr) {};
        node(int val_) : val(val_), siz(1), priority(rand()), count(1), rev(false), sl(nullptr), sr(nullptr) {};
    };

public:
    FHQ_Treap(unsigned int n) : root(nullptr), o(0), pool(new node[n]) { srand(time(0)); }
    ~FHQ_Treap() { delete[] pool; }

    node *root;
    node *pool;
    unsigned int o;

    void updateSize(node *no) {
      if (!no) return;
      no->siz = no->count + (no->sl ? no->sl->siz : 0) + (no->sr ? no->sr->siz : 0);
    }

    void pushDown(node *no) {
      if (!no) return;
      if (no->rev) {
        swap(no->sl, no->sr);
        if (no->sl) no->sl->rev ^= 1;
        if (no->sr) no->sr->rev ^= 1;
        no->rev = false;
      }
    }

    void merge(node *&t, node *l, node *r) {
      pushDown(l);
      pushDown(r);
      if (!l || !r) {
        t = l ? l : r;
      } else {
        if (l->priority > r->priority) {
          merge(l->sr, l->sr, r);
          t = l;
        } else {
          merge(r->sl, l, r->sl);
          t = r;
        }
      }
      if (t) updateSize(t);
    }

    void splitByVal(node *t, node *&l, node *&r, int val) {
      if (!t) { l = r = nullptr; return; }
      pushDown(t);
      if (t->val <= val) {
        l = t;
        splitByVal(t->sr, l->sr, r, val);
      } else {
        r = t;
        splitByVal(t->sl, l, r->sl, val);
      }
      updateSize(t);
    }

    void splitByRank(node *t, node *&l, node *&r, int rank) {
      if (!t) { l = r = nullptr; return; }
      pushDown(t);
      int leftSize = t->sl ? t->sl->siz : 0;
      if (rank <= leftSize) {
        r = t;
        splitByRank(t->sl, l, r->sl, rank);
      } else {
        l = t;
        splitByRank(t->sr, l->sr, r, rank - leftSize - t->count);
      }
      updateSize(t);
    }

    void insert(int val) {
      node *l = nullptr, *mid = nullptr, *r = nullptr;
      splitByVal(root, l, mid, val - 1);
      splitByVal(mid, mid, r, val);
      if (mid) {
        mid->count++;
        mid->siz++;
      } else {
        mid = pool + (++o);
        new (mid) node(val);
      }
      node *temp;
      merge(temp, l, mid);
      merge(root, temp, r);
    }

    void remove(int val) {
      node *l = nullptr, *mid = nullptr, *r = nullptr;
      splitByVal(root, l, mid, val - 1);
      splitByVal(mid, mid, r, val);
      if (mid) {
        if (mid->count > 1) {
          mid->count--;
          mid->siz--;
          node *temp;
          merge(temp, l, mid);
          merge(root, temp, r);
        } else {
          merge(root, l, r);
        }
      } else {
        merge(root, l, r);
      }
    }

    unsigned int getRankbyVal(int val) {
      node *a = nullptr, *b = nullptr;
      splitByVal(root, a, b, val - 1);
      unsigned int rank = a ? a->siz : 0;
      merge(root, a, b);
      return rank + 1;
    }

    int getValbyRank(int rank) {
      node *l = nullptr, *r = nullptr;
      splitByRank(root, l, r, rank);
      node *curr = l;
      while (curr && curr->sr) curr = curr->sr;
      int ans = curr ? curr->val : -INF;
      merge(root, l, r);
      return ans;
    }

    int getPre(int val) {
      node *p = root;
      int ans = -INF;
      while (p) {
        pushDown(p);
        if (p->val < val) {
          ans = max(ans, p->val);
          p = p->sr;
        } else {
          p = p->sl;
        }
      }
      return ans;
    }

    int getLas(int val) {
      node *p = root;
      int ans = INF;
      while (p) {
        pushDown(p);
        if (p->val > val) {
          ans = min(ans, p->val);
          p = p->sl;
        } else {
          p = p->sr;
        }
      }
      return ans;
    }
};

FHQ_Treap os(N);

void solve() {
  int n, opt, x;
  cin >> n;
  while (n--) {
    cin >> opt >> x;
    switch (opt) {
      case 1: os.insert(x); break;
      case 2: os.remove(x); break;
      case 3: cout << os.getRankbyVal(x) << '\n'; break;
      case 4: cout << os.getValbyRank(x) << '\n'; break;
      case 5: cout << os.getPre(x) << '\n'; break;
      case 6: cout << os.getLas(x) << '\n'; break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
