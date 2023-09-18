// 星际网络Ⅱ
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 15e4 + 10, M = 5e4 + 10, K = 170, B = 32, INF = 0x3f3f3f3f;
struct segtree {
  int n;
  struct node {
    int l, r, v, c, mn, mx;
  } e[N << 2];
#define l(p) e[p].l
#define r(p) e[p].r
#define v(p) e[p].v
#define c(p) e[p].c
#define mn(p) e[p].mn
#define mx(p) e[p].mx
  void up(int p) {
    v(p) = v(p << 1) + v(p << 1 | 1);
    mn(p) = min(mn(p << 1), mn(p << 1 | 1));
    mx(p) = max(mx(p << 1), mx(p << 1 | 1));
  }
  void bld(int p, int l, int r) {
    l(p) = l;
    r(p) = r;
    c(p) = 0;
    if (l == r) {
      v(p) = 0;
      mn(p) = INF;
      mx(p) = -INF;
      return;
    }
    int mid = l + r >> 1;
    bld(p << 1, l, mid);
    bld(p << 1 | 1, mid + 1, r);
    up(p);
  }
  void psd(int p) {
    if (c(p)) {
      v(p << 1) = r(p << 1) - l(p << 1) + 1;
      mn(p << 1) = min(mn(p << 1), c(p));
      mx(p << 1) = max(mx(p << 1), c(p));
      c(p << 1) = c(p);
      v(p << 1 | 1) = r(p << 1 | 1) - l(p << 1 | 1) + 1;
      mn(p << 1 | 1) = min(mn(p << 1 | 1), c(p));
      mx(p << 1 | 1) = max(mx(p << 1 | 1), c(p));
      c(p << 1 | 1) = c(p);
      c(p) = 0;
    }
  }
  void init(int _n) {
    n = _n;
    bld(1, 1, n);
  }
  void chg(int p, int ql, int qr, int v) {
    if (ql > qr) {
      return;
    }
    if (ql <= l(p) && r(p) <= qr) {
      v(p) = r(p) - l(p) + 1;
      mn(p) = min(mn(p), v);
      mx(p) = max(mx(p), v);
      c(p) = v;
      return;
    }
    psd(p);
    int mid = l(p) + r(p) >> 1;
    if (ql <= mid) {
      chg(p << 1, ql, qr, v);
    }
    if (qr > mid) {
      chg(p << 1 | 1, ql, qr, v);
    }
    up(p);
  }
  int cnt(int p, int ql, int qr) {
    if (ql <= l(p) && r(p) <= qr) {
      return v(p);
    }
    int mid = l(p) + r(p) >> 1, res = 0;
    psd(p);
    if (ql <= mid) {
      res += cnt(p << 1, ql, qr);
    }
    if (qr > mid) {
      res += cnt(p << 1 | 1, ql, qr);
    }
    return res;
  }
  int amn(int p, int ql, int qr) {
    if (ql <= l(p) && r(p) <= qr) {
      return mn(p);
    }
    int mid = l(p) + r(p) >> 1, res = INF;
    psd(p);
    if (ql <= mid) {
      res = min(res, amn(p << 1, ql, qr));
    }
    if (qr > mid) {
      res = min(res, amn(p << 1 | 1, ql, qr));
    }
    return res;
  }
  int amx(int p, int ql, int qr) {
    if (ql <= l(p) && r(p) <= qr) {
      return mx(p);
    }
    int mid = l(p) + r(p) >> 1, res = -INF;
    psd(p);
    if (ql <= mid) {
      res = max(res, amx(p << 1, ql, qr));
    }
    if (qr > mid) {
      res = max(res, amx(p << 1| 1, ql, qr));
    }
    return res;
  }
} seg;
int n, m, q, op, c;
array<int, B> f[N];
auto cal(string s) {
  int d = 0;
  array<int, B> ans = {0};
  for (auto &y : s) {
    if (y == ':') {
      d++;
      continue;
    }
    int &v = ans[d];
    if ('a' <= y && y <= 'f') {
      v = v * 16 + (y - 'a') + 10;
    } else {
      v = v * 16 + (y - '0');
    }
  }
  return ans;
}

auto add_one(array<int, B> y) {
  y[n / 16 - 1]++;
  for (int i = B - 1; i; --i) {
    if (y[i] >= 65536) {
      y[i] -= 65535;
      y[i - 1]++;
    }
  }
  return y;
}
int g(array<int, B> v) {
  int x = lower_bound(f, f + c, v) - f;
  return x + 1;
}

struct ask {
  int op, x;
  string s, t;
  void rd() {
    cin >> op;
    if (op == 1) {
      cin >> x;
    }
    cin >> s;
    f[c++] = cal(s);
    if (op == 2) {
      t = s;
    } else {
      cin >> t;
      f[c++] = cal(t);
      f[c] = add_one(f[c - 1]);
      c++;
    }
  }
  void sol() {
    int l = g(cal(s)), r = g(cal(t)), w = seg.cnt(1, l, r);
    int mn = seg.amn(1, l, r), mx = seg.amx(1, l, r);
    if (op == 1) {
      if (!w || (w < r - l + 1) && mn == mx && mn == x) {
        seg.chg(1, l, r, x);
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if (op == 2) {
      cout << (mn == INF ? 0 : mn) << endl;
    } else {
      cout << (w == r - l + 1 && mn == mx ? mn : 0) << endl;
    }
  }
} e[M];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= q; ++i) {
    e[i].rd();
  }
  sort(f, f + c);
  c = unique(f, f + c) - f;
  seg.init(c + 5);
  for (int i = 1; i <= q; ++i) {
    e[i].sol();
  }
  return 0;
}