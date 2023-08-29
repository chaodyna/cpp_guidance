#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
	int j = 0;
	int n = nums.size();
	for(i = 0; i < n; i++) {
            if(nums[i] == val) {
                continue;
	    }
            nums[j] = nums[i];
            j++;
        }
        return j;
    }
};

int main() {
    Solution st;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    cout << st.removeElement(nums, val) << endl;
}
