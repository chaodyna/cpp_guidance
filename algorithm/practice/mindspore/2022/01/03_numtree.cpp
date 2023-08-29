
#include <iostream>
#include <vector>
using namespace std;

int numTree(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i - 1; j++) {
            dp[i] += dp[j] * dp[(i - 1) - j];
	}
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    int ans = numTree(n);
    cout << ans << endl;
    return 0;
}
