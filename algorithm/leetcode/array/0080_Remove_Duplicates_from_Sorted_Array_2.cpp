/**
 * @file 0080_Remove_Duplicates_from_Sorted_Array_2.cpp
 * @author chaodyna (li0331_1@163.com)
 * @brief
 * @version 0.1
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 */

#include <iostream>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    int i = 0;
    for (int n : nums) {
      if (i < 2 || n > nums[i - 2]) {
        nums[i++] = n;
      }
    }
    return i;
  }
};

int main() {
  Solution st;
  std::vector<int> num = {0, 0, 1, 1, 1, 1, 2, 3, 3};
  int res = st.removeDuplicates(num);
  std::cout << "case 2: " << std::endl;
  std::cout << "the ans is: " << res << std::endl;
  return 0;
}