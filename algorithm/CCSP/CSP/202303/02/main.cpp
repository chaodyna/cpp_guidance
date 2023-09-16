// 垦田计划
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100100;
typedef long long ll;
ll t[N], c[N];
ll cc[N];

int main() {
  ll n, m, k, maxn = 0;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> c[i];
    cc[t[i]] += c[i];
    maxn = max(maxn, t[i]);
  }
  for (int i = maxn; i >= k; i--) {
    if(m > cc[i]) {
      if (i == k) {
        cout << k << endl;
        break;
      }
      m = m - cc[i];
      cc[i - 1] = cc[i - 1] + cc[i];
    } else {
      cout << i << endl;
      break;
    }
  }
}