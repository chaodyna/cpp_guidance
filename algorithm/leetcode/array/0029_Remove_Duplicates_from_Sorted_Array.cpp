/**
 * @file 0029_Remove_Duplicates_from_Sorted_Array.cpp
 * @author chaodyna (li0331_1@163.com)
 * @brief
 * @version 0.1
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

#include <iostream>
#include <vector>
class Solution {
public:
  int removeDuplicates(std::vector<int>& nums) {
    if(nums.empty()) {
      return 0;
    }
    int k = 0;
    for(int i = 1; i < nums.size(); ++i) {
      if(nums[k] != nums[i]) {
        nums[++k] = nums[i];
      }
    }
    return k + 1;
  }
};

int main() {
  Solution st;
  std::cout << "case 1:" << std::endl;
  std::vector<int> num = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int res = st.removeDuplicates(num);
  std::cout << "the ans is: " << res << std::endl;
}
