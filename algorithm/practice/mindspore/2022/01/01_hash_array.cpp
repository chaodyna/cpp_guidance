#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int countNum(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    unordered_map<int, int> mymap(n);
    for(int i = 0; i < n; ++i) {
        mymap[nums[i]]++;
    }
    for(int i = 0; i < n; ++i) {
        if(mymap[nums[i]] > n / 2) {
            ans = nums[i];
	    break;
	}
    }
    return ans;
}

int main() {
    vector<int> nums;
    int num;
    string s;
    cin >> s;
    for(auto i : s) {
        if(i >= '0' && i <= '9') {
            nums.push_back((i-'0'));
	}
    }

    int ans = countNum(nums);
    cout << ans << endl;
    return 0;
}
