// 田地丈量
#include <iostream>
using namespace std;

int main()
{
  int n, a, b;
  int x1, y1, x2, y2;
  int x, y;
  int sum = 0;
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    x = min(a, x2) - max(0, x1);
    y = min(b, y2) - max(0, y1);
    if (x >= 0 && y >= 0) {
      sum += x * y;
    }
  }
  cout << sum;
  return 0;
}